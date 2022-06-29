void int_disable(void);
void int_enable(void);

extern __attribute__((section (".ISR_I2C"), naked,weak))void ISR_I2C (void);	// 23: i2c
extern __attribute__((section (".ISR_UART"), naked,weak))void ISR_UART (void);	// 23: i2c
extern __attribute__((section (".ISR_EXT"), naked,weak))void ISR_EXT (void); 	// 25: gpio
extern __attribute__((section (".ISR_SPI"), naked,weak))void ISR_SPI (void);  // 26: spim end of transmission
extern __attribute__((section (".ISR_TIMER"), naked,weak))void ISR_TIMER (void);  // 26: spim end of transmission
extern __attribute__((section (".store_regs"), naked)) void store_regs();
extern __attribute__((section (".end_except"), naked)) void end_except();
extern __attribute__((section (".ISR_I2C_ASM"), naked)) void ISR_I2C_ASM();
extern __attribute__((section (".ISR_UART_ASM"), naked)) void ISR_UART_ASM();
extern __attribute__((section (".ISR_EXT_ASM"), naked)) void ISR_EXT_ASM();
extern __attribute__((section (".ISR_SPI_ASM"), naked)) void ISR_SPI_ASM();
extern __attribute__((section (".ISR_TIMER_ASM"), naked)) void ISR_TIMER_ASM();

