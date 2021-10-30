#include "uart.h"
#include "uart_def.h"
#include <unistd.h>

ssize_t _write(int fd, const void* ptr, size_t len) {
  volatile uint32_t	*sim_uart	= 	(volatile uint32_t*)0x800000;
  if (fd == STDOUT_FILENO) {
    for (size_t i = 0; i < len; ++i) {
      uart_putc(((const char*)ptr)[i]);
      *sim_uart = ((const char*)ptr)[i];
    }
    return len;
  }
  return -1;
}

/**
* Local variables
*/
static volatile uint32_t *m_uart;

/**
* uart_init: Initialise UART peripheral
*/
void uart_init(uint32_t buadrate)           
{
    uint32_t cfg = 0;
    m_uart = (volatile uint32_t *)UART_BASE_ADDR;

    // Soft reset
    cfg += (1 << U_CONTROL_RST_RX_SHIFT);
    cfg += (1 << U_CONTROL_RST_TX_SHIFT);
    cfg += (1 << U_CONTROL_IE_SHIFT);

   //m_uart[U_CONTROL/4]  = cfg;
    m_uart[U_CONTROL/4]  = cfg;
    m_uart[U_baudrate/4] = (50000000/buadrate) -1;
}

/**
* uart_putc: Polled putchar
*/
int uart_putc(char c)
{
    // While TX FIFO full

   //m_uart[U_TX/4] = c;
    m_uart[U_TX/4] = c;
     while (m_uart[U_STATUS/4] & (1 << U_STATUS_TXFULL_SHIFT)){

    }
    return 0;
}

/**
* art_haschar:
*/ 
int uart_haschar(void)
{
	return (m_uart[U_STATUS/4] & (1 << U_STATUS_RXVALID_SHIFT)) != 0;
}

/**
* uart_getchar: Read character from UART
*/ 
int uart_getchar(void)
{
    if (uart_haschar()){
        return (uint8_t)m_uart[U_RX/4];
        }
    else
        return -1;
}

/**
* uart_print_string: 
*/ 
void uart_puts(char *data)
{
	int x = 0;
	while (data[x] != 0)
		{
			uart_putc(data[x]);
			x++;
		}
}
 