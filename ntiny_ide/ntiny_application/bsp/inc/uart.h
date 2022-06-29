#ifndef __UART_H__
#define __UART_H__
#include <stdint.h>
/**
* Prototypes of Uart firmware \n
*/

void uart_init( uint32_t baudrate);
int  uart_putc(char c);
int  uart_haschar(void);
int  uart_getchar(void);
void uart_puts(char *data);


#endif
