void int_disable(void);
void int_enable(void);


__attribute__((section (".ISR_I2C_ASM"),)) __attribute__((interrupt())) __attribute__((weak))void ISR_I2C_ASM();
__attribute__((section (".ISR_UART_ASM"))) __attribute__((interrupt())) __attribute__((weak))void ISR_UART_ASM();
__attribute__((section (".ISR_EXT_ASM"))) __attribute__((interrupt())) __attribute__((weak))void ISR_EXT_ASM();
__attribute__((section (".ISR_SPI_ASM"))) __attribute__((interrupt())) __attribute__((weak))void ISR_SPI_ASM();
__attribute__((section (".ISR_TIMER_ASM"))) __attribute__((interrupt())) __attribute__((weak))void ISR_TIMER_ASM();


