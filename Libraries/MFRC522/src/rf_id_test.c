#include "mfrc522.h"
//#include "uart.h"
//#include "ee_printf.h"
#include "spi.h"
#include "timer.h"
uint8_t rf_id_test(uint8_t *messg){

    //uart_puts ("starting...\n");
	uint8_t str[6];
	spi_init(1,1,0);
	spi_set_sck_ratio (50);


	mfrc522_init();
	uint8_t byte;

	byte = mfrc522_request(PICC_REQALL,str);
			uint8_t str1[MAX_LEN] = {0x00};
			if(byte == CARD_FOUND)
			{
				byte = mfrc522_get_card_serial(str1);
				if(byte == CARD_FOUND)
				{
					//uart_puts((char*)str1);
					for(int i = 0; i < 4  ; i++){
						//ee_printf("%X,",str1[i]);
						*(messg+i) = str1[i];

					}
					//uart_putc('\n');
					
					return 1;
				}
			}
	delay_ms(500);
	
	return 0;
}