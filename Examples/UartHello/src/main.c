/*****************************************************************************
 * @file     main.c  (Examples/UartHello)
 * @brief    Print a banner and echo characters from the UART RX FIFO.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "ntiny.h"
#include "uart.h"

int main(void)
{
    uart_init(NTINY_DEFAULT_BAUD);
    uart_puts("ntiny-sdk: hello, world\r\n");

    for (;;) {
        int c = uart_getchar();
        if (c >= 0) {
            uart_putc((char)c);     /* echo */
        }
    }
}
