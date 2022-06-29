#include "keypad.h"
#include "gpio.h"
#include "timer.h"
char getkey()
{  
    gpio_reset();
    gpio_set(0x0);                                  // setting output register to 0
    gpio_set_ddr(gpio_check_pin_mode()&0xfff0);     // setting GPIO[3:0] to input   rows
    gpio_set_ddr(gpio_check_pin_mode()|0x0070);     // setting GPIO[6:4] to output  column
     gpio_set(0x0); 
    
  
    
    for (int i = 0; i<3; i++)       // give stimulus at the columns and read from rows
    {   
        gpio_write_pin(4+i,1);
        
        
            for (int j = 0; j<4; j++)
            {
                if (gpio_read_pin(j)&1) // row is hit
                {  
                     delay_ms(10);
                    if (gpio_read_pin(j)&1)  {    // debounce
                         gpio_write_pin(4+i,0);
                        return findkey(j,i);
                    }
                }
            }
        gpio_write_pin(4+i,0);
    }
    
    return 12;
}
char keys[12] = {'1','2','3','4','5','6','7','8','9','*','0','#'};
char findkey(uint8_t row, uint8_t column)
{
    return keys [row*3 + column];
} 