#include "dht.h"

int DHTPIN;
int dht11_dat[5] = { 0, 0, 0, 0, 0 };

void dht_pin_init(int pin){DHTPIN = pin;}


int dht_read(float *temp, float *humid)
{
    
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; /* fahrenheit */

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	/* pull pin down for 18 milliseconds */
	gpio_mode( DHTPIN, OUTPUT );
	gpio_write_pin( DHTPIN, LOW );
	delay_ms( 18 );
	/* then pull it up for 40 microseconds */
	gpio_write_pin( DHTPIN, HIGH );
	delay_us( 40 );
	/* prepare to read the pin */
	gpio_mode( DHTPIN, INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( gpio_read_pin( DHTPIN ) == laststate )
		{
			counter++;
			delay_us( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = gpio_read_pin( DHTPIN );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) && (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
        *humid = dht11_dat[0] + 0.1*dht11_dat[1];
		*temp = dht11_dat[2] + 0.1*dht11_dat[3];
        return 1;
	}else  {
        return 0;               //signifies data invalid
	}
}
