/*
 * fft_main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: shaheer
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "ee_printf.h"
#include "init.h"
#include "uart.h"
#include "microFFT.h"


/* FFT Parameters and Variables */
#define FFT_samples             128      //This value MUST ALWAYS be a power of 2
#define FFT_samplingFrequency   200
#define FFT_ampFactor           FFT_samples/8.0f
float vReal[FFT_samples];
float vImag[FFT_samples];

/* Simulated signal */
// Sinusoidal Parameters and Variables
#define sin_signals_number      3
float sin_amplitude[sin_signals_number] = {10,     60,    40};
float sin_frequency[sin_signals_number] = {10,      20,     65};

// Signal Parameters and Variable
#define signal_samples          FFT_samples
#define signal_Offset           20000
float signal[signal_samples];

/* Auxiliar Functions */
// Generate a signal from the sum of sinusoidal signals
void SignalGenerator(float* signal_output, size_t signal_output_len, size_t signals_number, float* signals_amplitud, float* signals_frequency, uint16_t signal_offset, uint16_t sampling_frequency);
// Remove the offset of a set of samples
void RemoveOffset(float* array, size_t array_len);

int main()
{
    // FFT Initialization
	int_disable();
	uart_init(9600);
    FFT_Init(vReal, vImag, FFT_samples, FFT_samplingFrequency);

    // Reading of the signal
    SignalGenerator(signal, signal_samples, sin_signals_number, sin_amplitude, sin_frequency, signal_Offset, FFT_samplingFrequency);

    // Signal Conditioning
    RemoveOffset(signal, signal_samples);

    // Memory copy
    memcpy(vReal, signal, sizeof(float)*signal_samples);

    // while(1)
    // {
        FFT_Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD); // Recommended use for high frequencies. Relative to Sampling Frequency. In this case: 70Hz
        FFT_Compute(FFT_FORWARD);
        FFT_ComplexToMagnitude();

        float amp, freq;
        FFT_MajorPeak(&amp, &freq, FFT_ampFactor);
        ee_printf("Mag: %f, Freq: %f\n", amp, freq);
    // }


    return 0;
}

void SignalGenerator(float* signal_output, size_t signal_output_len, size_t signals_number, float* signals_amplitud, float* signals_frequency, uint16_t signal_offset, uint16_t sampling_frequency)
{
    for (uint16_t i = 0; i < signals_number; i++)
    {
        float cycles = (((signal_output_len-1) * (float)signals_frequency[i]) / sampling_frequency); //Number of signal cycles that the sampling will read
        for (uint16_t j = 0; j < signal_output_len; j++)
        {
            signal_output[j] += (float)((signals_amplitud[i] * (sin((j * (6.28318531 * cycles)) / signal_output_len))) / 2.0);/* Build data with positive and negative values*/
        }
    }

    for (size_t i = 0; i < signal_output_len; i++)
    {
        signal_output[i] += signal_offset;
    }
}

void RemoveOffset(float* array, size_t array_len)
{
	// calculate the mean of vData
	float mean = 0;
	for (size_t i = 0; i < array_len; i++)
	{
		mean += array[i];
	}
	mean /= array_len;
	// Subtract the mean from vData
	for (size_t i = 0; i < array_len; i++)
	{
		array[i] -= mean;
	}
}

