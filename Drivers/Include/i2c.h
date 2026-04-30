/*****************************************************************************
 * @file     i2c.h
 * @brief    Public API for the NTiny I2C master driver.
 *
 *           The I2C clock is derived from F_CPU through a ÷5 stage and an
 *           additional programmable prescaler:
 *               prescaler = (F_CPU / (5 * i2c_freq)) - 1
 *
 *           Bus transactions are blocking: callers issue START, push or
 *           pull bytes, and finally pass last=1 on the final byte to emit
 *           STOP / NACK as appropriate.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>

/** Initialise the I2C master and program its clock divider. */
void I2C_init (uint32_t i2c_freq);

/** Disable the I2C master. */
void I2C_close(void);

/** Issue START + slave address; @p read = 0 for write, 1 for read. */
void I2C_start(uint32_t slave_addr, uint32_t read);

/** Write one byte; @p last = 1 to emit STOP after the byte. */
void I2C_write(uint8_t data, uint8_t last);

/** Read one byte; @p last = 1 to NACK + STOP, 0 for ACK + continue. */
int  I2C_read (uint8_t last);

#endif /* __I2C_H__ */
