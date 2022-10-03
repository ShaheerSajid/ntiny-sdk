#include "init.h"
#include "csr.h"

int main(void);
void int_disable(void) {
  csr_clear(mstatus , (1<<3) );
}
void int_enable(void) {
  csr_set(mstatus , (1<<3) );
}

extern __attribute__((section (".ISR_I2C"), naked,weak))void ISR_I2C (void)
{
 // __asm("nop");
  //__asm("jalr x0, x1");
}
extern __attribute__((section (".ISR_UART"), naked,weak))void ISR_UART (void)
{
  //__asm("nop");
  //__asm("jalr x0, x1");
}
extern __attribute__((section (".ISR_EXT"), naked,weak))void ISR_EXT (void)
{
 // __asm("nop");
  //__asm("jalr x0, x1");
}
extern __attribute__((section (".ISR_SPI"), naked,weak))void ISR_SPI (void)
{
  //__asm("nop");
  //__asm("jalr x0, x1");
}
extern __attribute__((section (".ISR_TIMER"), naked,weak))void ISR_TIMER (void)
{
  //__asm("nop");
  //__asm("jalr x0, x1");
}

extern __attribute__((section (".store_regs"), naked))
void store_regs()
{
  __asm("sw  x3, 0x00(x2)");  // gp
  __asm("sw  x4, 0x04(x2)");  // tp
  __asm("sw  x5, 0x08(x2)");  // t0
  __asm("sw  x6, 0x0c(x2)");  // t1
  __asm("sw  x7, 0x10(x2)");  // t2
  __asm("sw x10, 0x14(x2)");  // a0
  __asm("sw x11, 0x18(x2)");  // a1
  __asm("sw x12, 0x1c(x2)");  // a2
  __asm("sw x13, 0x20(x2)");  // a3
  __asm("sw x14, 0x24(x2)");  // a4
  __asm("sw x15, 0x28(x2)");  // a5
  __asm("sw x16, 0x2c(x2)");  // a6
  __asm("sw x17, 0x30(x2)");  // a7
  __asm("sw x28, 0x34(x2)");  // t3
  __asm("sw x29, 0x38(x2)");  // t4
  __asm("sw x30, 0x3c(x2)");  // t5
  __asm("sw x31, 0x40(x2)");  // t6
  __asm("csrr x28, 0x7B0");
  __asm("csrr x29, 0x7B1");
  __asm("csrr x30, 0x7B2");
  __asm("sw x28, 0x44(x2)");  // lpstart[0]
  __asm("sw x29, 0x48(x2)");  // lpend[0]
  __asm("sw x30, 0x4C(x2)");  // lpcount[0]
  __asm("csrr x28, 0x7B4");
  __asm("csrr x29, 0x7B5");
  __asm("csrr x30, 0x7B6");
  __asm("sw x28, 0x50(x2)");  // lpstart[1]
  __asm("sw x29, 0x54(x2)");  // lpend[1]
  __asm("sw x30, 0x58(x2)");  // lpcount[1]
  __asm("jalr x0, x1");
}
// load back registers from stack
extern __attribute__((section (".end_except"), naked))
void end_except()
{
  __asm("lw x28, 0x50(x2)");  // lpstart[1]
  __asm("lw x29, 0x54(x2)");  // lpend[1]
  __asm("lw x30, 0x58(x2)");  // lpcount[1]
  __asm("csrrw x0, 0x7B4, x28");
  __asm("csrrw x0, 0x7B5, x29");
  __asm("csrrw x0, 0x7B6, x30");
  __asm("lw x28, 0x44(x2)");  // lpstart[0]
  __asm("lw x29, 0x48(x2)");  // lpend[0]
  __asm("lw x30, 0x4C(x2)");  // lpcount[0]
  __asm("csrrw x0, 0x7B0, x28");
  __asm("csrrw x0, 0x7B1, x29");
  __asm("csrrw x0, 0x7B2, x30");
  __asm("lw  x3, 0x00(x2)");
  __asm("lw  x4, 0x04(x2)");
  __asm("lw  x5, 0x08(x2)");
  __asm("lw  x6, 0x0c(x2)");
  __asm("lw  x7, 0x10(x2)");
  __asm("lw x10, 0x14(x2)");
  __asm("lw x11, 0x18(x2)");
  __asm("lw x12, 0x1c(x2)");
  __asm("lw x13, 0x20(x2)");
  __asm("lw x14, 0x24(x2)");
  __asm("lw x15, 0x28(x2)");
  __asm("lw x16, 0x2c(x2)");
  __asm("lw x17, 0x30(x2)");
  __asm("lw x28, 0x34(x2)");
  __asm("lw x29, 0x38(x2)");
  __asm("lw x30, 0x3c(x2)");
  __asm("lw x31, 0x40(x2)");
  __asm("lw  x1, 0x5C(x2)");
  __asm("addi x2, x2, 96");
  __asm("mret");
}


extern __attribute__((section (".ISR_I2C_ASM"), naked))
void ISR_I2C_ASM()
{
  __asm("addi x2, x2, -96");
  __asm("sw x1, 0x5C(x2)");
  __asm("jal x1, store_regs");
  __asm("la x1, end_except");
  __asm("jal x0, ISR_I2C");
}

extern __attribute__((section (".ISR_UART_ASM"), naked))
void ISR_UART_ASM()
{
  __asm("addi x2, x2, -96");
  __asm("sw x1, 0x5C(x2)");
  __asm("jal x1, store_regs");
  __asm("la x1, end_except");
  __asm("jal x0, ISR_UART");
}

extern __attribute__((section (".ISR_EXT_ASM"), naked))
void ISR_EXT_ASM()
{
  __asm("addi x2, x2, -96");
  __asm("sw x1, 0x5C(x2)");
  __asm("jal x1, store_regs");
  __asm("la x1, end_except");
  __asm("jal x0, ISR_EXT");
}

extern __attribute__((section (".ISR_SPI_ASM"), naked))
void ISR_SPI_ASM()
{
  __asm("addi x2, x2, -96");
  __asm("sw x1, 0x5C(x2)");
  __asm("jal x1, store_regs");
  __asm("la x1, end_except");
  __asm("jal x0, ISR_SPI");
}
/*
extern __attribute__((section (".ISR_TIMER_ASM"), naked))
void ISR_TIMER_ASM()
{
  __asm("addi x2, x2, -96");
  __asm("sw x1, 0x5C(x2)");
  __asm("jal x1, store_regs");
  __asm("la x1, end_except");
  __asm("jal x0, ISR_TIMER");
}
*/
extern __attribute__((section (".RESET_HANDLER"), naked))
void RESET_HANDLER()
{
	__asm("mv  x1, x0");
	__asm("mv  x2, x1");
	__asm("mv  x3, x1");
	__asm("mv  x4, x1");
	__asm("mv  x5, x1");
	__asm("mv  x6, x1");
	__asm("mv  x7, x1");
	__asm("mv  x8, x1");
	__asm("mv  x9, x1");
	__asm("mv x10, x1");
	__asm("mv x11, x1");
	__asm("mv x12, x1");
	__asm("mv x13, x1");
	__asm("mv x14, x1");
	__asm("mv x15, x1");
	__asm("mv x16, x1");
	__asm("mv x17, x1");
	__asm("mv x18, x1");
	__asm("mv x19, x1");
	__asm("mv x20, x1");
	__asm("mv x21, x1");
	__asm("mv x22, x1");
	__asm("mv x23, x1");
	__asm("mv x24, x1");
	__asm("mv x25, x1");
	__asm("mv x26, x1");
	__asm("mv x27, x1");
	__asm("mv x28, x1");
	__asm("mv x29, x1");
	__asm("mv x30, x1");
	__asm("mv x31, x1");
	__asm("csrrw x0, mtvec, x0");
	__asm(".option push\n"
	".option norelax\n"
	"la gp, __global_pointer$\n"
	".option pop");
	__asm("la sp, __stack_top");
	__asm("add s0, sp, zero");
	extern char __bss_start,__BSS_END__;
	char *dst;
	for (dst = &__bss_start; dst< &__BSS_END__; dst++)
	{
	*dst = 0;
	__asm("nop");
	}
	main();
}


extern __attribute__((section (".init"), naked))
void _init(){
	__asm("jal x0, RESET_HANDLER");
	__asm("jal x0, ISR_TIMER_ASM");	 
	__asm("jal x0, ISR_UART_ASM");	
	__asm("jal x0, ISR_I2C_ASM");	   
	__asm("jal x0, ISR_SPI_ASM");
	__asm("jal x0, ISR_EXT_ASM");

}
