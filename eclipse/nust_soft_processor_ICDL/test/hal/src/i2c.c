
#include "i2c.h"
#include "i2c_defs.h"


static volatile uint32_t *m_I2C;

void I2C_init ( uint32_t base_addr)
{ 
	  uint32_t clock_prescaler =0;
	  uint32_t ctrl_reg = 0;
	 m_I2C =	(volatile uint32_t *)base_addr;
	 // Reset
	 m_I2C[REG_CTRL] = 0;
	
	 
	 m_I2C[REG_CMD] = 0;
	// m_I2C[REG_CTRL] = 0;
	 clock_prescaler = 0x33F;
	 ctrl_reg		= 0x80;
	
	 m_I2C[REG_CLK_PRESCALER] = clock_prescaler;
		// m_I2C[REG_CLK_PRESCALER] = clock_prescaler;
	
	// m_I2C[REG_CMD] = 0;
	m_I2C[REG_CTRL] = ctrl_reg;
	// m_I2C[REG_CTRL] = 0x0ff; 
	
}

void I2C_close (void)
{	
	m_I2C[REG_CMD] = 0x0;

}

void I2C_write(uint8_t slave_addr,uint8_t w_data)
{
	// transmit address

	m_I2C[REG_TX] = (slave_addr<<1);
	m_I2C[REG_CMD] = 0x90;
	// wait while transfer is complete
	while ( (m_I2C[REG_STATUS]&0x02));
	
	
	// transmit data;
	m_I2C[REG_TX] = w_data;
	m_I2C[REG_CMD] = 0x50;
	
	//wait while transfer is complete
	while ( (m_I2C[REG_STATUS]&0x02));
	
	
	
}


uint8_t I2C_read(uint8_t slave_addr  )
{
	// variable to recieve data
	uint8_t rxd;
	
	// transmit address

	m_I2C[REG_RX] = (slave_addr<<1)&0x0E;
	m_I2C[REG_CMD] = 0x90;
	// wait while transfer is complete
	while ( !((m_I2C[REG_STATUS] & 1 << 6)&(m_I2C[REG_CMD]&0x30)));
	
	// read data
	m_I2C[REG_CMD] = 0x20;
	// wait while transfer is complete
	while ( !((m_I2C[REG_STATUS] & 1 << 6)&(m_I2C[REG_CMD]&0x30)));
	rxd = m_I2C[REG_RX];
	
	m_I2C[REG_CMD] = 0x04;	// stop I2C;
	
}

