#ifndef __ADXL_345_H__
#define __ADXL_345_H__

#include <stdint.h>

void        adxl345_reset_code();
void        adxl345_test_code ();
void        SPI_write_reg (uint8_t registerAddress , uint8_t value );
void        SPI_read_reg (char registerAddress, int numBytes, char * values);

#endif