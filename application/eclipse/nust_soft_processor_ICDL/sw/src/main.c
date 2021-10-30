#include <stdio.h>
#include "uart.h"
#include "gpio.h"
#include "timer.h"





int main(void)
{
	uart_init(115200);
	while(1){
		printf("Hello World\n");
		
		}
      return 1;

}
