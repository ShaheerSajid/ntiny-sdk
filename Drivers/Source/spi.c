/*****************************************************************************
 * @file     spi.c
 * @brief    NTiny SPI master peripheral driver.
 *
 *           Built on the AXI Quad-SPI compatible register layout exposed by
 *           the SoC's SPI core. The driver pokes the control register with
 *           SPE | MASTER | MANUAL_SS plus the requested CPOL/CPHA/lsb_first
 *           bits, then performs a soft reset of both FIFOs.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "spi.h"
#include "spi_defs.h"

/** Cached pointer to the SPI register block. */
static volatile uint32_t *m_spi;

void spi_set_sck_ratio(uint8_t ratio)
{
    m_spi[SPI_CLK_RATIO / 4] = ratio;
}

void spi_init(int cpol, int cpha, int lsb_first)
{
    m_spi = (volatile uint32_t *)SPI_BASE_ADDR;

    uint32_t cfg = (1u << SPI_CR_SPE_SHIFT)
                 | (1u << SPI_CR_MASTER_SHIFT)
                 | ((uint32_t)cpol << SPI_CR_CPOL_SHIFT)
                 | ((uint32_t)cpha << SPI_CR_CPHA_SHIFT)
                 | (1u << SPI_CR_MANUAL_SS_SHIFT)
                 | ((uint32_t)lsb_first << SPI_CR_LSB_FIRST_SHIFT);

    m_spi[SPI_CR  / 4] = cfg;
    m_spi[SPI_SSR / 4] = ~0u;          /* deselect everything */
    m_spi[SPI_SRR / 4] = 0x0000000A;   /* magic soft-reset code per IP spec */
}

void spi_cs(uint32_t value)
{
    /* SSR is active-low; user passes a positive mask of slaves to select. */
    m_spi[SPI_SSR / 4] = ~value;
}

uint8_t spi_sendrecv(uint8_t data)
{
    m_spi[SPI_DTR / 4] = data;

    /* Three nops give the FIFO write time to propagate before we begin
     * polling TX_EMPTY -- the IP otherwise races a fresh write against
     * the previous transaction's drain. */
    __asm("nop"); __asm("nop"); __asm("nop");

    while (!(m_spi[SPI_SR / 4] & (1u << SPI_SR_TX_EMPTY_SHIFT))) {
        __asm("nop");
    }

    return (uint8_t)m_spi[SPI_DRR / 4];
}

void spi_readblock(uint8_t *ptr, int length)
{
    for (int i = 0; i < length; i++) {
        *ptr++ = spi_sendrecv(0xFF);
    }
}

void spi_writeblock(char *ptr)
{
    while (*ptr != 0) {
        spi_sendrecv(*ptr++);
    }
}
