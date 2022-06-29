#include <stdlib.h>
#include<stdio.h>
#include <stdint.h>
#include <string.h>
/// inlcuding uart library
#include "uart.h"
#include "uart_def.h"

#include "mfrc522.h"
#include "timer.h"




/*--------------------------------------------------------------------------------------
  Includes
--------------------------------------------------------------------------------------*/





// fucntion prototype
//int compare_valid(char* inchar);

uint8_t run_rfid();


// global variables

uint8_t ptr [6];
char messg [12];
//char valid_id[12]="97,a4,49,25";

uint8_t read_id = 1;




/// main fucntion
int main(void)

{

uart_init(115200);
gpio_mode(1,1);
gpio_write_pin(1,0);

while (1)
{
//uart_puts("running\n");
run_rfid();
}

return 0;
}

uint8_t run_rfid ()
{
uint8_t test = 0;
// uint64_t cycles = clock();
test = rf_id_test(ptr);
// printf("rfid test time %"PRIu64" : \n",clock()-cycles);
// uart_puts("over_here");
if (test)
{
//uart_puts("here\n");
if (ptr)
{
for ( int i=0; i<4; i++)
{
char temp_char [20];

itoa(ptr[i],temp_char,16);
messg[i*3] = temp_char[0];
messg[(i*3)+1]= temp_char[1];
messg[(i*3)+2] = ',';

}
messg[11] ='\0';
uart_puts("Card number is .. \n");
uart_puts(messg);
uart_puts("\n");
gpio_write_pin(1,1);

delay_ms(2000);
gpio_write_pin(1,0);
return 1;

}
}

return 0;

}

/*int compare_valid(char* inchar)
{
int i=0;
for (i = 0; i<11;i++)
{
if( *(inchar+i) != valid_id[i] )
{
break ;

}
}
return (i==11)?1:0;
}*/
