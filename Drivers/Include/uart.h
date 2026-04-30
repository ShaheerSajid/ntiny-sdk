/*****************************************************************************
 * @file     uart.h
 * @brief    Public API for the NTiny UART peripheral driver.
 *
 *           The driver targets a memory-mapped 8-bit UART with a programmable
 *           baud-rate divisor. All transmit/receive primitives are polled.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef __UART_H__
#define __UART_H__

#include "uart_def.h"
#include <stdint.h>

/** Initialise UART for a given baud rate. Must be called before any I/O. */
void uart_init(uint32_t baudrate);

/** Send one character; blocks while TX FIFO is full. Returns 0 on success. */
int  uart_putc(char c);

/** @return 1 if a byte is waiting in the RX FIFO, 0 otherwise. */
int  uart_haschar(void);

/** Non-blocking receive: returns the byte read or -1 if RX is empty. */
int  uart_getchar(void);

/** Send a NUL-terminated string. */
void uart_puts(char *data);

/** Blocking receive of @p length bytes into @p data. */
void uart_gets(char *data, uint8_t length);

#endif
