#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "csr.h"
#include "gpio.h"
#include "timer.h"
//#include "i2c.h"
#include "uart.h"
#include "pwm.h"


char str[10] = "";
char snum[10];
char snum_speed[20];
char snum_speed_f[20];
int val = 0;
unsigned int t1 = 0;
float speed = 0;
int counter = 0;
int prev = 0;

int main(void)
{
	uart_init(115200);
	init();

	timer_set_prescaler(1); // set value by which you want to divide the clock frequency
	timer_set_compare(-1);
	timer_set_count(0);
	timer_start();

	set_compare (0);
	pwm_start();

	gpio_mode(30, 1);
	gpio_mode(29, 1);
	gpio_mode(27, 0);

	gpio_write_pin(30, 0);
	gpio_write_pin(29, 0);
	while(1){

		if(uart_haschar()) {
			char y = uart_getchar();
			if(y == 'F')
			{
				uart_puts("Forward\n");
				gpio_write_pin(30, 1);
				gpio_write_pin(29, 0);

			}
			else if(y == 'B')
			{
				uart_puts("Backward\n");
				gpio_write_pin(30, 0);
				gpio_write_pin(29, 1);
			}
			else if(y == 'S')
			{
				uart_puts("Stop\n");
				gpio_write_pin(30, 0);
				gpio_write_pin(29, 0);
			}
			else if(y == 'C')
			{
				str[0] = '\0';
			}
			else if(y == 'L')
			{
				uart_puts("Setting Speed: LOW\n");
				set_compare (100);
			}
			else if(y == 'H')
			{
				uart_puts("Setting Speed: HIGH\n");
				set_compare (255);
			}
			else if(y == 'M')
			{
				uart_puts("Setting Speed: MEDIUM\n");
				set_compare (150);
			}
		}

	}
	return 1;

}
