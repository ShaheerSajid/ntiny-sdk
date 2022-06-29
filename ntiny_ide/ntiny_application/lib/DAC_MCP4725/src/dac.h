#ifndef __DAC_H__
#define __DAC_H__

#include <stdint.h>

void init_Dac(uint8_t dac_address);
void set_Dac_voltage(uint16_t output);
void dac_test_sin_wave();


#endif