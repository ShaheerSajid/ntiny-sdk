/*****************************************************************************
 * @file     spi.h
 * @brief    Public API for the NTiny SPI master driver.
 *
 *           The driver supports the full SPI mode matrix (CPOL/CPHA combos)
 *           plus optional LSB-first framing. Chip-select is software
 *           managed via spi_cs() so multiple slaves can share the bus.
 *
 *           Mode reference:
 *             SPI_MODE0 -- CPOL=0, CPHA=0
 *             SPI_MODE1 -- CPOL=0, CPHA=1
 *             SPI_MODE2 -- CPOL=1, CPHA=0
 *             SPI_MODE3 -- CPOL=1, CPHA=1
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>

/** Set the SPI clock divider (output rate = F_CPU / (2 * (ratio + 1))). */
void    spi_set_sck_ratio(uint8_t ratio);

/** Configure the master with the given mode and bit-order. */
void    spi_init(int cpol, int cpha, int lsb_first);

/** Drive the slave-select output (write the CS mask; ~value internally). */
void    spi_cs(uint32_t value);

/** Full-duplex byte exchange: writes @p ch on MOSI, returns the MISO byte. */
uint8_t spi_sendrecv(uint8_t ch);

/** Read @p length bytes into @p ptr by clocking out 0xFF for each. */
void    spi_readblock(uint8_t *ptr, int length);

/** Send a NUL-terminated byte string. */
void    spi_writeblock(char *ptr);

#endif /* __SPI_H__ */
