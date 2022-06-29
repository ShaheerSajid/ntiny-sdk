#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
void I2C_init ( uint32_t base_addr,	uint32_t i2c_freq);
void I2C_close(void );
void I2C_start (uint32_t slave_addr, uint32_t read);
void I2C_write(uint8_t data,uint8_t last);
uint8_t I2C_read(uint8_t last  );
void i2c_test();
void reset_mpu_6050();
void run_mpu6050 ();
//void I2C_transmit_byte ( uint8_t txd );
//uint8_t I2C_recieve_byte (void );


#endif