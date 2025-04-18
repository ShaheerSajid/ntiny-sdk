#include "lcd.h"
#include "timer.h"
#include "gpio.h"

int rs;
int en;
int D0;
int D1;
int D2;
int D3;
int D4;
int D5;
int D6;
int D7;

void lcd_data_write(unsigned char data)
{
	gpio_write_pin(D0, (data&0x01)==0x01);
	gpio_write_pin(D1, (data&0x02)==0x02);
	gpio_write_pin(D2, (data&0x04)==0x04);
	gpio_write_pin(D3, (data&0x08)==0x08);
	gpio_write_pin(D4, (data&0x10)==0x10);
	gpio_write_pin(D5, (data&0x20)==0x20);
	gpio_write_pin(D6, (data&0x40)==0x40);
	gpio_write_pin(D7, (data&0x80)==0x80);
	gpio_write_pin(rs, 1);
	gpio_write_pin(en, 1);
	delay_us(1);
	gpio_write_pin(en, 0);
	delay_us(100);
}
void lcd_cmd_write(unsigned char data)
{
	gpio_write_pin(D0, (data&0x01)==0x01);
	gpio_write_pin(D1, (data&0x02)==0x02);
	gpio_write_pin(D2, (data&0x04)==0x04);
	gpio_write_pin(D3, (data&0x08)==0x08);
	gpio_write_pin(D4, (data&0x10)==0x10);
	gpio_write_pin(D5, (data&0x20)==0x20);
	gpio_write_pin(D6, (data&0x40)==0x40);
	gpio_write_pin(D7, (data&0x80)==0x80);
	gpio_write_pin(rs, 0);
	gpio_write_pin(en, 1);
	delay_us(1);
	gpio_write_pin(en, 0);
	delay_us(100);
}

void lcd(int Rs, int En, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
{
	rs = Rs;
	en = En;
	D0 = d0;
	D1 = d1;
	D2 = d2;
	D3 = d3;
	D4 = d4;
	D5 = d5;
	D6 = d6;
	D7 = d7;
	gpio_mode(rs,1);
	gpio_mode(en,1);
	gpio_mode(D0,1);
	gpio_mode(D1,1);
	gpio_mode(D2,1);
	gpio_mode(D3,1);
	gpio_mode(D4,1);
	gpio_mode(D5,1);
	gpio_mode(D6,1);
	gpio_mode(D7,1);
}

void lcd_print(char *data)
{
	int x = 0;
	while (data[x] != 0)
		{
			lcd_data_write(data[x]);
			x++;
		}
}


void lcd_init()
{

	delay_ms(2);
	lcd_cmd_write(0x38);
	lcd_cmd_write(0x0C);
	lcd_cmd_write(0x01);
	delay_ms(2);
	lcd_cmd_write(0x06);
}
void lcd_setCursor(unsigned char x, unsigned char y)
{
	unsigned char data = 0;
	if(y)
		data = 0xc0;
	else
		data = 0x80;
	data = data + x;
	lcd_cmd_write(data);
	delay_us(100);
}
void lcd_scroll(int dir)
{
	if(dir)
	lcd_cmd_write(0x18); //left
	else
	lcd_cmd_write(0x1C); //right
}
void lcd_clear()
{
	lcd_cmd_write(0x01);
	lcd_cmd_write(0x02);
}


