/*****************************************************************************
 * @file     startup_ntiny.c
 * @brief    Reset handler, vector table, and weak ISRs for the NTiny SoC.
 * @version  1.0.0
 *
 *  Layout:
 *    .init           -- 12-entry vector table at the trap base. Each slot
 *                       is a single jal-relative jump; mtvec is set to
 *                       this label OR'd with 1 to enter vectored mode.
 *    .RESET_HANDLER  -- entry from slot 0 of the vector table. Initialises
 *                       general-purpose registers, configures mtvec and
 *                       mstatus.FS, sets up stack/global pointer, zeroes
 *                       BSS, then calls SystemInit() and main().
 *    .ISR_*_ASM      -- weak C functions tagged with __interrupt that
 *                       generate proper save/restore frames; the user can
 *                       override any of them at link time.
 *
 *  Slot mapping (matches RISC-V "interrupt cause" codes; see Privileged
 *  Architecture spec §3.1.20):
 *    [ 0] reset / direct-mode trap
 *    [ 3] machine software interrupt (CLINT msip)
 *    [ 7] machine timer interrupt    (CLINT mtimecmp <= mtime)
 *    [11] machine external interrupt (PLIC claim)
 *    others -- ISR_DEFAULT_ASM
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "init.h"
#include "csr.h"

extern int main(void);
extern void SystemInit(void);

/* --------------------------------------------------------------------------
 * Public IRQ enable / disable helpers (toggle mstatus.MIE).
 * --------------------------------------------------------------------------*/
void int_disable(void) { csr_clear(mstatus, (1 << 3)); }
void int_enable (void) { csr_set  (mstatus, (1 << 3)); }

/* --------------------------------------------------------------------------
 * Default (weak) interrupt service routines. Override any of these in your
 * application by defining a function with the same name.
 * --------------------------------------------------------------------------*/
void ISR_DEFAULT_ASM(void) { }
void ISR_EXT_ASM    (void) { }
void ISR_SOFT_ASM   (void) { }
void ISR_TIMER_ASM  (void) { }

/* --------------------------------------------------------------------------
 * RESET_HANDLER -- C entry point with hand-rolled prologue.
 * --------------------------------------------------------------------------*/
__attribute__((section (".RESET_HANDLER"), naked))
void RESET_HANDLER(void)
{
    /* Zero the entire integer register file (x1..x31) for deterministic
     * state at boot; some implementations leave them as X (don't-care)
     * until first written. */
    __asm("mv  x1, x0"); __asm("mv  x2, x1"); __asm("mv  x3, x1");
    __asm("mv  x4, x1"); __asm("mv  x5, x1"); __asm("mv  x6, x1");
    __asm("mv  x7, x1"); __asm("mv  x8, x1"); __asm("mv  x9, x1");
    __asm("mv x10, x1"); __asm("mv x11, x1"); __asm("mv x12, x1");
    __asm("mv x13, x1"); __asm("mv x14, x1"); __asm("mv x15, x1");
    __asm("mv x16, x1"); __asm("mv x17, x1"); __asm("mv x18, x1");
    __asm("mv x19, x1"); __asm("mv x20, x1"); __asm("mv x21, x1");
    __asm("mv x22, x1"); __asm("mv x23, x1"); __asm("mv x24, x1");
    __asm("mv x25, x1"); __asm("mv x26, x1"); __asm("mv x27, x1");
    __asm("mv x28, x1"); __asm("mv x29, x1"); __asm("mv x30, x1");
    __asm("mv x31, x1");

    /* Point mtvec at the .init vector table and enable VECTORED mode (bit 0
     * of mtvec). In vectored mode the trap target = (mtvec & ~3) +
     * (mcause & 0x3F) * 4, so each interrupt source jumps directly to its
     * own slot in the table. */
    __asm("la t0, _init\n"
          "ori t0, t0, 1\n"
          "csrw mtvec, t0");

    /* Enable the floating-point unit by setting mstatus.FS = 01 (Initial).
     * Without this any F-extension instruction traps with an illegal-
     * instruction exception. */
    __asm("li t0, (1 << 13)\n"
          "csrs mstatus, t0");

    /* Set up gp for GP-relative addressing. The .option norelax block
     * prevents the assembler from collapsing the 'la' into a relaxed form
     * that would itself rely on gp. */
    __asm(".option push\n"
          ".option norelax\n"
          "la gp, __global_pointer$\n"
          ".option pop");

    /* Stack starts at the top of RAM and grows downward. */
    __asm("la sp, __stack_top");
    __asm("add s0, sp, zero");

    /* Zero .bss. The linker provides __bss_start / __BSS_END__. */
    extern char __bss_start, __BSS_END__;
    char *dst;
    for (dst = &__bss_start; dst < &__BSS_END__; dst++) {
        *dst = 0;
        __asm("nop");
    }

    /* Per CMSIS convention, hand control to SystemInit() before main() so
     * device-specific clock / FPU / interrupt configuration can run
     * outside the startup file. */
    SystemInit();

    main();

    /* If main() returns, fall through to a controlled re-entry rather than
     * letting execution dribble into adjacent sections. */
    __asm("jal x0, RESET_HANDLER");
}

/* --------------------------------------------------------------------------
 * Vector table. Placed at the start of memory by the linker; ENTRY(_init)
 * makes this the program entry symbol.
 * --------------------------------------------------------------------------*/
__attribute__((section (".init"), naked))
void _init(void)
{
    __asm("jal x0, RESET_HANDLER");     /* [ 0] reset                */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 1]                      */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 2]                      */
    __asm("jal x0, ISR_SOFT_ASM");      /* [ 3] machine software irq */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 4]                      */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 5]                      */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 6]                      */
    __asm("jal x0, ISR_TIMER_ASM");     /* [ 7] machine timer irq    */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 8]                      */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [ 9]                      */
    __asm("jal x0, ISR_DEFAULT_ASM");   /* [10]                      */
    __asm("jal x0, ISR_EXT_ASM");       /* [11] machine external irq */
}
