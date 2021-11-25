#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
void I2C_init(uint32_t base_addr );
void I2C_close(void );
void I2C_write(uint8_t slave_addr,uint8_t w_data);
uint8_t I2C_read(uint8_t slave_addr  );
void i2c_test();
//void I2C_transmit_byte ( uint8_t txd );
//uint8_t I2C_recieve_byte (void );


#endif