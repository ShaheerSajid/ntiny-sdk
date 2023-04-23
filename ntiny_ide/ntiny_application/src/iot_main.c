#include "dht.h"
#include <stdlib.h>
#include <stdint.h>
#include "init.h"
#include "uart.h"
#include "timer.h"
#include "gpio.h"
#include "ee_printf.h"
#include "pwm.h"

/// main fucntion
int main(void) {
	//UART
	int_disable();
	uart_init(9600);

	//variable declarations for temperature

	dht_pin_init(0);
	int cnt = 0;
	float temp[1];
	float humid[1];

	//Initialise LIGHT and Turn it OFF
	gpio_mode(1, 1);
	gpio_mode(3, 1);
	gpio_mode(5, 1);
	int state1 = 1;
	int state2 = 1;
	int state3 = 1;
	gpio_write_pin(1, state1);
	gpio_write_pin(3, state2);
	gpio_write_pin(5, state3);
	//Initialise FAN and lower the Speed

	while (1) {

		if (dht_read(temp, humid)) {
			//TERMINAL
			//Uncomment to use term=minal interface
			//ee_printf("Temp %d: %.1f;",cnt,*temp);
			//ee_printf("Hum %d: %.1f;",cnt,*humid);

			//Receiver Interface
			//Uncomment to use the receiver interface
			//ee_printf("%.1f,", cnt, *temp);
			//ee_printf("%.1f;", cnt, *humid);
			//cnt++;
			ee_printf("%d\r\n",(int)*temp);
		}

		if (uart_haschar()) {
			char y = uart_getchar();
			if (y == 'L') {
				state1 = !state1;
				gpio_write_pin(1, state1);
			} else if (y == 'M') {
				state2 = !state2;
				gpio_write_pin(3, state2);
			} else if (y == 'N') {
				state3 = !state3;
				gpio_write_pin(5, state3);
			}

		}
		delay_ms(1000);
	}
	return 0;
}
