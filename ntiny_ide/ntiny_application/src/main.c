#include <stdlib.h>
#include <math.h>
#include "ee_printf.h"
#include "init.h"
#include "csr.h"
// #include "plic.h"
// #include "gpio.h"
#include "uart.h"
#include "i2c.h"
#include "timer.h"
#include <time.h>

int main()
{
	int_disable();
	I2C_init (400000);
	uart_init(250000);

	I2C_start(0x53,0);
	I2C_write(0x2D,0);
	I2C_write(8,1);

	I2C_start(0x53,0);
	I2C_write(0x2C,0);
	I2C_write(0x0d,1);

	// set range 16
	I2C_start(0x53,0);
	I2C_write(0x31,0);
	I2C_start(0x53,1);
	uint8_t format = I2C_read(1);

	format &= ~0x0F;
	format |= 0x11;
	format |= 0x08;

    I2C_start(0x53,0);
    I2C_write(0x31,0);
    I2C_write(format,1);

  while(1)
  {
    uint64_t t1 = clock();
    uint16_t AccX,AccY,AccZ;

    I2C_start(0x53,0);
    I2C_write(0x32,0);
    I2C_start(0x53,1); // start in read

    uint16_t x_0 = I2C_read(0);
    uint16_t x_1 = I2C_read(0);
    AccX = ((x_1 & 0x1f) << 8 | x_0) ; // X-axis value
    int16_t xf = AccX;
    if(xf > 4095)
    {
      xf = xf - 8192;
    }
    float xa = xf * 0.003906;

    uint16_t y_0 = I2C_read(0);
    uint16_t y_1 = I2C_read(0);
    AccY = ((y_1 & 0x1f) << 8 | y_0) ; // X-axis value
    int16_t yf = AccY;
    if(yf > 4095)
    {
      yf = yf - 8192;
    }
    float ya = yf * 0.003906;

    uint16_t z_0 = I2C_read(0);
    uint16_t z_1 = I2C_read(1);
    AccZ = ((z_1 & 0x1f) << 8 | z_0) ; // X-axis value

    int16_t zf = AccZ;
    if(zf > 4095)
    {
      zf = zf - 8192;
    }
    float za = zf * 0.003906;

    float roll = atan(ya / sqrt(pow(xa, 2) + pow(za, 2))) * 180 / 3.1415;
    float pitch = atan(-1 * xa / sqrt(pow(ya, 2) + pow(za, 2))) * 180 / 3.1415;

    uint64_t t2 = clock();

    ee_printf("%3.2f\n", pitch);

    delay_ms(10);
  }
}
