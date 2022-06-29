//---------------------------------------------------------------------------------------------
// source file for defining helper fucntions for ADXL 345 sensor
//---------------------------------------------------------------------------------------------
#include "adxl_345.h"
#include "spi.h"

//---------------------------------------------------------------------------------------------
// SPI_write_reg:  fucntion for writinig adxl registers via spi interface
//---------------------------------------------------------------------------------------------

void SPI_write_reg( uint8_t registerAddress , uint8_t value  )
{
     // below line for debug
    //uart_puts ("Entered SPI read reg function ..\n");
    spi_cs (0x01);
    spi_sendrecv(registerAddress);
    spi_sendrecv(value);
    spi_cs (0x0);

}

//---------------------------------------------------------------------------------------------
// SPI_read_reg:  fucntion for reading adxl registers via spi interface
//---------------------------------------------------------------------------------------------

void SPI_read_reg(char registerAddress, int numBytes, char * values)
{
     // below line for debug
    //uart_puts ("Entered SPI read reg function ..\n");
    //Since we're performing a read operation, the most significant bit of the register address should be set.
    char address = 0x80 | registerAddress;
    //If we're doing a multi-byte read, bit 6 needs to be set as well.
    if(numBytes > 1)address = address | 0x40;

    spi_cs (0x01);

    
    //Transfer the starting register address that needs to be read.
    spi_sendrecv(address);

    spi_readblock(values,numBytes);

    spi_cs (0x00);

}


