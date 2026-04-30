#include "init.h"
#include "csr.h"
#include "gpio.h"


void int_disable(void) {
  csr_clear(mstatus , (1<<3) );
}
void int_enable(void) {
  csr_set(mstatus , (1<<3) );
}


#include "spi_defs.h"
#include "gpio_defs.h"

#define WRITE_ENABLE  0x06
#define WRITE_DISABLE 0x04
#define READ_STATUS   0x05
#define READ_BYTES    0x03
#define READ_ID       0xAB
#define FAST_READ     0x0B
#define WRITE_BYTES   0x02
#define ERASE_BULK    0xC7
#define ERASE_BLOCK	  0xD8
#define ERASE_SECTOR  0x20



__attribute__((section (".spi_cs_custom"), optimize("Os", "no-inline")))
void spi_cs_custom(volatile uint32_t* m_spi, uint32_t value)
{
    m_spi[SPI_SSR/4] = ~value;
}

__attribute__((section (".spi_sendrecv_custom"), optimize("Os", "no-inline")))
uint8_t spi_sendrecv_custom(volatile uint32_t* m_spi, uint8_t data)
{
    m_spi[SPI_DTR/4] = data;
    __asm("nop");
    __asm("nop");
    __asm("nop");
    while (!(m_spi[SPI_SR/4] & (1 << SPI_SR_TX_EMPTY_SHIFT)))
        {
                __asm("nop");
        }

    return (uint8_t)m_spi[SPI_DRR/4];
}

__attribute__((section (".boot_seq_copier"), naked, optimize("Os")))
void boot_seq_copier()
{
	int_disable();
	volatile uint32_t *gpio__base_addr = (volatile uint32_t *)0x400000;
	gpio__base_addr[DDR] |= (1<<0);
	gpio__base_addr[DDR] |= (1<<1);

	gpio__base_addr[Dout] |= (1<<0);
	//spi_init(0, 0, 0);
	uint32_t cfg = 0;
	volatile uint32_t *m_spi = (volatile uint32_t *)SPI_BASE_ADDR;
	cfg += (1 << SPI_CR_SPE_SHIFT);
	cfg += (1 << SPI_CR_MASTER_SHIFT);
	cfg += (0 << SPI_CR_CPOL_SHIFT);
	cfg += (0 << SPI_CR_CPHA_SHIFT);
	cfg += (1 << SPI_CR_MANUAL_SS_SHIFT);
	cfg += (0 << SPI_CR_LSB_FIRST_SHIFT);
	m_spi[SPI_CR/4]  = cfg;
	m_spi[SPI_SSR/4] = ~0;
	// Soft reset
	m_spi[SPI_SRR/4] = 0x0000000A;
	//frequency 1MHZ = 50Mhz/50
	m_spi[SPI_CLK_RATIO/4] = 50;
	//reset enable
	spi_cs_custom(m_spi,1);
	spi_sendrecv_custom(m_spi,0x66);
	spi_cs_custom(m_spi,0);
	//reset
	spi_cs_custom(m_spi,1);
	spi_sendrecv_custom(m_spi,0x99);
	spi_cs_custom(m_spi,0);

	//load flash
	uint32_t b0, b1, b2, b3;
	uint32_t w;
	volatile uint32_t *j = (volatile uint32_t *)(0x0);
	//turn on fast read
	spi_cs_custom(m_spi,1);
	spi_sendrecv_custom(m_spi,FAST_READ);
	spi_sendrecv_custom(m_spi,0x00);
	spi_sendrecv_custom(m_spi,0x00);
	spi_sendrecv_custom(m_spi,0x00);
	spi_sendrecv_custom(m_spi,0x00);
	//read instruction
	for (int l = 0; l < 0x8000; l+=4)
	{
		b0 = spi_sendrecv_custom(m_spi,0xFF);
		b1 = spi_sendrecv_custom(m_spi,0xFF);
		b2 = spi_sendrecv_custom(m_spi,0xFF);
		b3 = spi_sendrecv_custom(m_spi,0xFF);
		w = (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
		if (w == 0x00000000) break;

		*j = w ;
		j += 1;
	}
	spi_cs_custom(m_spi,0);

	gpio__base_addr[Dout] |= (1<<1);
	//turn on fast read
	spi_cs_custom(m_spi,1);
	spi_sendrecv_custom(m_spi,FAST_READ);
	spi_sendrecv_custom(m_spi,0x01);
	spi_sendrecv_custom(m_spi,0x00);
	spi_sendrecv_custom(m_spi,0x00);
	spi_sendrecv_custom(m_spi,0x00);
	//read data
	volatile uint32_t *k = (volatile uint32_t *)(0x10000);
	for (int l = 0; l < 0x2000; l+=4)
	{
		b0 = spi_sendrecv_custom(m_spi,0xFF);
		b1 = spi_sendrecv_custom(m_spi,0xFF);
		b2 = spi_sendrecv_custom(m_spi,0xFF);
		b3 = spi_sendrecv_custom(m_spi,0xFF);
		w = (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
		if (w == 0x00000000) break;

		*k = w ;
		k += 1;
	}
	spi_cs_custom(m_spi,0);
	gpio__base_addr[Dout] &= ~(1<<0);
	gpio__base_addr[Dout] &= ~(1<<1);

	//load data

	//jump to init
	__asm("li x5, 0x0"); //start of application
	__asm("jalr x0, 0(x5)");
	//_init();
}

