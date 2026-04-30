/*****************************************************************************
 * @file     uart.c
 * @brief    NTiny UART peripheral driver (polled).
 *
 *           Baud-rate divisor formula:   div = (F_CPU / baud) - 1
 *           Default F_CPU is 50 MHz; override in ntiny_config.h.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "uart.h"
#include "ntiny_config.h"
#include <stdint.h>

/** Cached pointer to the UART register block. */
static volatile uint32_t *m_uart;

void uart_init(uint32_t baudrate)
{
    m_uart = (volatile uint32_t *)UART_BASE_ADDR;

    /* Soft-reset both FIFOs and enable the interrupt line; the driver
     * itself does not depend on interrupts but applications routinely
     * re-use this bit, so we leave it set. */
    uint32_t cfg = (1 << U_CONTROL_RST_RX_SHIFT)
                 | (1 << U_CONTROL_RST_TX_SHIFT)
                 | (1 << U_CONTROL_IE_SHIFT);

    m_uart[U_CONTROL  / 4] = cfg;
    m_uart[U_baudrate / 4] = (F_CPU / baudrate) - 1;
}

int uart_putc(char c)
{
    m_uart = (volatile uint32_t *)UART_BASE_ADDR;
    m_uart[U_TX / 4] = (uint8_t)c;

#if !NTINY_VERILATOR
    /* Wait until the TX FIFO accepts the byte. Skipped under Verilator
     * to keep simulation cycles bounded. */
    while (m_uart[U_STATUS / 4] & (1 << U_STATUS_TXFULL_SHIFT)) {
    }
#endif
    return 0;
}

int uart_haschar(void)
{
    return (m_uart[U_STATUS / 4] & (1 << U_STATUS_RXVALID_SHIFT)) != 0;
}

int uart_getchar(void)
{
    return uart_haschar() ? (uint8_t)m_uart[U_RX / 4] : -1;
}

void uart_puts(char *data)
{
    while (*data) {
        uart_putc(*data++);
    }
}

void uart_gets(char *data, uint8_t length)
{
    for (uint8_t i = 0; i < length; i++) {
        while (!uart_haschar()) {
        }
        data[i] = (uint8_t)m_uart[U_RX / 4];
    }
}
