#include <stdlib.h>
#include <stdint.h>
#include "init.h"
#include "uart.h"
#include "ee_printf.h"
#include "timer.h"
#include "gpio.h"
#include "pwm.h"



int main(void )
{
uart_init(9600);
uart_puts("ntiny alive..");
gpio_mode(6,1);
gpio_write_pin(6,1);

    int count;
    char input[500];
    while (1)
    {
         if(uart_haschar()) // CHECK FOR AVAILABILITY OF SERIAL DATA


{
count = 0; // Reset the counter to zero

while(uart_haschar() && count < 500) {

input[count] = uart_getchar(); // Read 1 Byte of data and store it in the input[] variable

count++; // increment counter
delay_ms(5);
}

// PRINTING RFID TAG

for(int i=0;i<count;i++)
{
uart_putc(input[i]);
}
uart_puts("\n read complete\n");
uart_putc('\n');
gpio_write_pin(6,0);
delay_ms(5000);
gpio_write_pin(6,1);

    }



}
    return 0;
    }
