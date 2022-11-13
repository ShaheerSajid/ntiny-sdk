/*
 * main.c
 *
 *  Created on: 28 Dec 2021
 *      Author: shaheer
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "init.h"
#include "uart.h"
#include "timer.h"
#include "csr.h"
#include "gpio.h"
#include "spi.h"
#include "ee_printf.h"
#include "microFFT.h"
#include <time.h>
#include <math.h>

/* FFT Parameters and Variables */
#define FFT_samples             256
#define FFT_samplingFrequency   2000
#define FFT_ampFactor           100.0f//FFT_samples/8.35f
float vReal[FFT_samples];
float vImag[FFT_samples];
#define signal_samples          FFT_samples
float signal[signal_samples];

void RemoveOffset(float *array, size_t array_len) {
	// calculate the mean of vData
	float mean = 0;
	for (size_t i = 0; i < array_len; i++) {
		mean += array[i];
	}
	mean /= array_len;
	// Subtract the mean from vData
	for (size_t i = 0; i < array_len; i++) {
		array[i] -= mean;
	}
}

/*!
 LTC2308: 16-bit 8-channel 100ksps ADC
 SPI DATA FORMAT (MSB First):
 Byte #1                           Byte #2
 Data Out :  D15 D14 D13 D12 D11 D10  D9  D8    D7  D6  D5  D4  D3  D2  D1  D0
 Data In  :  SD  OS  S1  S0  UNI GAIN NAP SLP   X   X   X   X   X   X   X   X
 SD   : Single/Differential Bit
 OS   : ODD/Sign Bit
 Sx   : Address Select Bit
 UNI  : Unipolar/Bipolar Bit
 GAIN : Input Span Bit
 NAP  : Nap Mode Bit
 SLP  : Sleep Mode Bit
 Dx   : Data Bits
 X    : Don't care
 */
// Single-Ended Channel Address
#define LTC2308_CH0             0x80
#define LTC2308_CH1             0xC0
#define LTC2308_CH2             0x90
#define LTC2308_CH3             0xD0
#define LTC2308_CH4             0xA0
#define LTC2308_CH5             0xE0
#define LTC2308_CH6             0xB0
#define LTC2308_CH7             0xF0
// Unipolar Mode Command
#define LTC2308_UNIPOLAR_MODE   0x08
#define LTC2308_BIPOLAR_MODE    0x00
// Single-Ended Mode Command
#define LTC2308_SINGLE_ENDED_MODE   0x80
#define LTC2308_DIFFERENTIAL_MODE  0x00
// gain
#define LTC2308_LOW_GAIN_MODE   0x00
#define LTC2308_HIGH_GAIN_MODE  0x04
// Sleep Mode Command
#define LTC2308_SLEEP_MODE      0x01
#define LTC2308_NORMAL_MODE     0x00
// Nap Mode Command
#define LTC2308_NAP_MODE      0x02

void LTC2308_read(uint8_t adc_command, uint16_t *adc_code);
float LTC2308_code_to_voltage(uint16_t adc_code, float vref,
		uint8_t uni_bipolar);
void spi_transfer_word(uint16_t tx, uint16_t *rx) {
	union {
		uint8_t b[2];
		uint16_t w;
	} data_tx;

	union {
		uint8_t b[2];
		uint16_t w;
	} data_rx;

	data_tx.w = tx;

	spi_cs(1);

	data_rx.b[1] = spi_sendrecv(data_tx.b[1]);
	data_rx.b[0] = spi_sendrecv(data_tx.b[0]);

	*rx = data_rx.w;

	spi_cs(0);
}
void LTC2308_read(uint8_t adc_command, uint16_t *adc_code) {
	spi_transfer_word((uint16_t) (adc_command << 8), adc_code);
}
float LTC2308_code_to_voltage(uint16_t adc_code, float vref,
		uint8_t uni_bipolar) {
	float voltage;
	float sign = 1;

	if (uni_bipolar == LTC2308_UNIPOLAR_MODE) {
		voltage = (float) adc_code;
		voltage = voltage / (powf(2, 16) - 1);
	} else {
		vref = vref / 2;
		if ((adc_code & 0x8000) == 0x8000) {
			adc_code = (adc_code ^ 0xFFFF) + 1;
			sign = -1;
		}
		voltage = sign * (float) adc_code;
		voltage = voltage / (powf(2, 15) - 1);
	}
	voltage = voltage * vref;
	return (voltage);
}

/*

 FIR filter designed with
 http://t-filter.appspot.com

 sampling frequency: 2000 Hz

 * 0 Hz - 400 Hz
 gain = 1
 desired ripple = 5 dB
 actual ripple = 4.1393894966071585 dB

 * 500 Hz - 1000 Hz
 gain = 0
 desired attenuation = -40 dB
 actual attenuation = -40.07355419274887 dB

 */

#define FIRFILTER_TAP_NUM 27

typedef struct {
	float history[FIRFILTER_TAP_NUM];
	unsigned int last_index;
} firFilter;

void firFilter_init(firFilter *f);
void firFilter_put(firFilter *f, float input);
float firFilter_get(firFilter *f);

static float filter_taps[FIRFILTER_TAP_NUM] = {
  -0.00831551551091961,
  0.013703008819203263,
  0.008125257257844519,
  -0.016492140608177244,
  0.0016884593471476863,
  -0.006913035271285734,
  0.031391613465220604,
  0.022740863526439146,
  -0.11984908724116768,
  0.05186355035523468,
  0.1713774031685405,
  -0.20124347467075912,
  -0.08441813048666605,
  0.281631430933639,
  -0.08441813048666605,
  -0.20124347467075912,
  0.1713774031685405,
  0.05186355035523468,
  -0.11984908724116768,
  0.022740863526439146,
  0.031391613465220604,
  -0.006913035271285734,
  0.0016884593471476863,
  -0.016492140608177244,
  0.008125257257844519,
  0.013703008819203263,
  -0.00831551551091961
};

void firFilter_init(firFilter *f) {
	int i;
	for (i = 0; i < FIRFILTER_TAP_NUM; ++i)
		f->history[i] = 0;
	f->last_index = 0;
}

void firFilter_put(firFilter *f, float input) {
	f->history[f->last_index++] = input;
	if (f->last_index == FIRFILTER_TAP_NUM)
		f->last_index = 0;
}

float firFilter_get(firFilter *f) {
	float acc = 0;
	int index = f->last_index, i;
	for (i = 0; i < FIRFILTER_TAP_NUM; ++i) {
		index = index != 0 ? index - 1 : FIRFILTER_TAP_NUM - 1;
		acc += f->history[index] * filter_taps[i];
	};
	return acc;
}

int main(void) {
	int_disable();
	uart_init(115200);
	spi_init(1, 1, 0);
	spi_set_sck_ratio(200);
	gpio_mode(0, 0);

	gpio_mode(1, 0);
	gpio_mode(2, 0);
	gpio_mode(3, 0);
	gpio_mode(4, 0);
	gpio_mode(5, 0);

	uint8_t adc_command;
	uint16_t adc_code;
	float adc_voltage;
	float amp, freq;
	// Single-ended, CH0, unipolar, low gain, normal mode.
	adc_command = LTC2308_CH0 | LTC2308_UNIPOLAR_MODE | LTC2308_LOW_GAIN_MODE
			| LTC2308_NORMAL_MODE;

	FFT_Init(vReal, vImag, FFT_samples, FFT_samplingFrequency);
	firFilter fir;
	firFilter_init(&fir);


	float signalFrequency1 = gpio_read_pin(1)? 200 : 0;
	float signalFrequency2 = gpio_read_pin(2)? 400 : 0;
	float signalFrequency3 = gpio_read_pin(3)? 600 : 0;
	float signalFrequency4 = gpio_read_pin(4)? 800 : 0;
	float signalFrequency5 = gpio_read_pin(5)? 1000 : 0;
	float cycles1 = (((signal_samples - 1) * signalFrequency1)
			/ FFT_samplingFrequency);
	float cycles2 = (((signal_samples - 1) * signalFrequency2)
			/ FFT_samplingFrequency);
	float cycles3 = (((signal_samples - 1) * signalFrequency3)
			/ FFT_samplingFrequency);
	float cycles4 = (((signal_samples - 1) * signalFrequency4)
			/ FFT_samplingFrequency);
	float cycles5 = (((signal_samples - 1) * signalFrequency5)
			/ FFT_samplingFrequency);

	for (int j = 0; j < signal_samples; j++) {
		//LTC2308_read(adc_command, &adc_code);
		adc_voltage = ((1.0 * (sinf((j * (6.283 * cycles1)) / signal_samples))) / 2.0)
					+ ((1.0 * (sinf((j * (6.283 * cycles2)) / signal_samples))) / 2.0)
					+ ((1.0 * (sinf((j * (6.283 * cycles3)) / signal_samples))) / 2.0)
					+ ((1.0 * (sinf((j * (6.283 * cycles4)) / signal_samples))) / 2.0)
					+ ((1.0 * (sinf((j * (6.283 * cycles5)) / signal_samples))) / 2.0)
					+ ((1.0 * (sinf((j * (6.283 * (((signal_samples - 1) * (200+rand()%800))/ FFT_samplingFrequency))) / signal_samples))) / 2.0)
					+ 3.0/*LTC2308_code_to_voltage(adc_code, 4.096,LTC2308_UNIPOLAR_MODE)*/;
		if (gpio_read_pin(0)) {
			firFilter_put(&fir, adc_voltage);
			vReal[j] = firFilter_get(&fir);
			//delay_us(300);
		} else {
			vReal[j] = adc_voltage;
			//delay_us(365);
		}
		vImag[j] = 0;
	}
	char sbuff[10];
	// Signal Conditioning
	RemoveOffset(vReal, signal_samples);
	unsigned int t1 = (unsigned int)clock();
	FFT_Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
	FFT_Compute(FFT_FORWARD);
	unsigned int t2 = (unsigned int)clock();
	itoa(t2-t1, sbuff, 10);
	uart_puts(sbuff);uart_putc('\n');
	//FFT_ComplexToMagnitude();
	//FFT_MajorPeak(&amp, &freq, FFT_ampFactor);
	//ee_printf("Major Peak: Mag= %0.2f, Freq= %0.2f\n", amp, freq);
	//char sbuff[10];
//	for (int i = 0; i < signal_samples /*/ 2*/; i++) {
/*		itoa(((int) (i * (float) FFT_samplingFrequency) / (float) FFT_samples),
				sbuff, 10);
		uart_puts(sbuff);
		uart_putc(',');
		itoa(vReal[i], sbuff, 10);
		uart_puts(sbuff);
		uart_putc('\n');*/
		//ee_printf("%.2f",
		//		(i * (float) FFT_samplingFrequency) / (float) FFT_samples);
		//ee_printf(",");

//		ee_printf("%.6f\n", vReal[i]);
//	}
	delay_ms(10000);
	//ee_printf("done\n");
	//uart_puts("done\n");
	return 0;
}

