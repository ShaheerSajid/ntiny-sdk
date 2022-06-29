#include "dac.h"
#include "i2c.h"




const uint16_t DACLookup_FullSine_5Bit[32] =
{
  2048, 2447, 2831, 3185, 3495, 3750, 3939, 4056,
  4095, 4056, 3939, 3750, 3495, 3185, 2831, 2447,
  2048, 1648, 1264,  910,  600,  345,  156,   39,
     0,   39,  156,  345,  600,  910, 1264, 1648
};


void init_Dac(uint8_t dac_address)
{
	//uart_puts("Turning DAC module on using I2C..\n");
   	I2C_init (0x2000000,400000);
	
}

void set_Dac_voltage(uint16_t output)
{
	uint8_t MCP4725_CMD_WRITEDAC = 0x40;
	I2C_start(0x60,0);
	// write to dac command
	I2C_write(MCP4725_CMD_WRITEDAC, 0);

	// write the upper data bits
	I2C_write(output/16, 0);
	// write the lower data bits
	I2C_write((output % 16) << 4, 1);
	//uart_puts("data send to DAC using I2C..\n");
}	


void dac_test_sin_wave(){


	init_Dac (0x62);

	while (1)
	{
		
		for (int i = 0; i < 32; i++)
		{
			set_Dac_voltage(DACLookup_FullSine_5Bit[i]);
		}
			
		//sleep for .5 sec
		//delay_ms(500);

	}
}