/*****************************************************************************
 * @file     i2c.c
 * @brief    NTiny I2C master peripheral driver.
 *
 *           Each transfer primitive writes a command byte to REG_CMD and
 *           then spins on the "transfer-in-progress" bit (status bit 1).
 *           Command encodings (REG_CMD):
 *             0x90 -- START + write address byte
 *             0x10 -- WRITE  (continuing)
 *             0x50 -- WRITE + STOP
 *             0x20 -- READ + ACK
 *             0x68 -- READ + NACK + STOP
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "i2c.h"
#include "i2c_defs.h"
#include "ntiny_config.h"

/** Cached pointer to the I2C register block. */
static volatile uint32_t *m_I2C;

void I2C_init(uint32_t i2c_freq)
{
    uint32_t clock_prescaler = (F_CPU / (5 * i2c_freq)) - 1;

    m_I2C = (volatile uint32_t *)BASE_ADDR;

    /* Reset state. */
    m_I2C[REG_CTRL] = 0;
    m_I2C[REG_CMD]  = 0;

    m_I2C[REG_CLK_PRESCALER] = clock_prescaler;

    /* Enable the I2C core (REG_CTRL[7] = i2c_en). */
    m_I2C[REG_CTRL] = 0x80;
}

void I2C_close(void)
{
    m_I2C[REG_CMD] = 0x0;
}

void I2C_start(uint32_t slave_addr, uint32_t read)
{
    /* 7-bit address shifted left, R/W bit ORed in. */
    m_I2C[REG_TX]  = ((slave_addr << 1) | (0x01 & read));
    m_I2C[REG_CMD] = 0x90;

    __asm("nop"); __asm("nop");
    while (m_I2C[REG_STATUS] & 0x02) {  /* wait while TIP */
    }
}

void I2C_write(uint8_t data, uint8_t last)
{
    m_I2C[REG_TX]  = data;
    m_I2C[REG_CMD] = last ? 0x50 : 0x10;

    __asm("nop"); __asm("nop");
    while (m_I2C[REG_STATUS] & 0x02) {
    }
}

int I2C_read(uint8_t last)
{
    m_I2C[REG_CMD] = last ? 0x68 : 0x20;

    __asm("nop"); __asm("nop");
    while (m_I2C[REG_STATUS] & 0x02) {
    }

    return m_I2C[REG_RX];
}
