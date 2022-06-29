#include "mpu_6050.h"
#include "i2c.h"


uint32_t AccX,AccY,AccZ;

void reset_mpu_6050 ()
{
	//uart_puts ("entered mpu reset fucntion..\n");
    //Wire.begin();                      // Initialize I2C comunication
	//uart_puts("Reseting MPU-6050 using I2C..\n");
   	I2C_init (0x2000000,400000);

    //Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
    I2C_start(0x68,0);
    //Wire.write(0x6B);                  // Talk to the register 6B
    I2C_write(0x6B,0);
    //Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
    I2C_write(0x00,1);
    //Wire.endTransmission(true);        //end the transmission
}

void run_mpu6050()
{		
		 //Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
    	 I2C_start(0x68,0);
    	  //Wire.write(0x3B);                  // Talk to the register 6B
   		 I2C_write(0x3B,0);
   		 I2C_start(0x68,1); // start in read
   		//For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet

 		 uint32_t x_0 =I2C_read(0);
		  uint32_t x_1 = I2C_read(0);
		  AccX = (x_0 << 8 | x_1) ; // X-axis value

 		 uint32_t y_0 =I2C_read(0);
		  uint32_t y_1 = I2C_read(0);
		  AccY = (y_0 << 8 | y_1) ; // X-axis value
	 	
		  uint32_t z_0 =I2C_read(0);
		  uint32_t z_1 = I2C_read(1);
		  AccZ = (z_0 << 8 | z_1) ; // X-axis value

        // for debug
        /*
		uart_puts("Running MPU-6050 using I2C..\n");
		 uart_puts("AccX: ");
		 char s_num [10];
		 itoa (AccX,s_num,10);
		 uart_puts (s_num);
		 uart_puts (" ");

		 uart_puts("AccY: ");
		 itoa (AccY,s_num,10);
		 uart_puts (s_num);
		 uart_puts (" ");

		 uart_puts("AccZ: ");
		 itoa (AccZ,s_num,10);
		 uart_puts (s_num);
		 uart_puts ("\n");
        */
}
	