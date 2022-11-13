#include "init.h"
#include "gpio.h"
#include "uart.h"
#include "uart_def.h"
#include "csr.h"
#include "timer.h"
#include "ee_printf.h"
#include <stdlib.h>
#include <stdint.h>

int dataPin = 1;
int clockPin = 3;
int latchPin = 5;
uint16_t i = 0;
uint16_t i_p = 0;


void ISR_TIMER_ASM()
{
	csr_clear(mstatus , (1<<3));
	i++;
	volatile uint32_t	*m_uart	= 	(volatile uint32_t *)UART_BASE_ADDR;
	volatile uint32_t	*sim_uart	= 	(volatile uint32_t*)0x800000;
    int x = 0;
	char *data = "Timer Interrupt\n";
	while (data[x] != 0)
		{
			*sim_uart = data[x];
			/*
			 m_uart[U_TX/4] = data[x];
			while (m_uart[U_STATUS/4] & (1 << U_STATUS_TXFULL_SHIFT)){

			}
			*/
			x++;
		}
}


char sbuf[20];
int main(void) {

	int_disable();
	uart_init(115200);

	gpio_mode(dataPin, 1);
	gpio_mode(clockPin, 1);
	gpio_mode(latchPin, 1);

	//gpio_mode(0,0);
	//gpio_set_interrupt();
	timer_set_prescaler(1); // set value by which you want to divide the clock frequency
	timer_set_compare(5000);
	timer_set_count(0);
	timer_start();
	csr_write(mie , (1<<7));//enable external

	int_enable();

	while (1) {

		gpio_write_pin(latchPin, 0);

		for (int j = 0; j < 16; j++) {
			gpio_write_pin(clockPin, 0);
			gpio_write_pin(dataPin, (i >> j) & 0x01);
			gpio_write_pin(clockPin, 1);
			gpio_write_pin(dataPin, 0);
		}
		gpio_write_pin(clockPin, 0);
		gpio_write_pin(latchPin, 1);
		//delay_ms(100);
		if(i != i_p)
		{
			//ee_printf("Counter: %d\n", i);
			itoa(i, sbuf,10);
			uart_puts(sbuf);
			uart_putc('\n');
			i_p = i;
		}

	}
}
