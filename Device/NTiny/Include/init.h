/*****************************************************************************
 * @file     init.h
 * @brief    Public declarations for startup-side helpers and weak ISRs.
 *
 *           The four ISR_* symbols below are *weak* by default. Override
 *           any of them in your application by defining a function with
 *           the same name -- the linker will replace the empty default
 *           with your handler.
 *
 *           The __attribute__((interrupt())) annotation makes GCC emit a
 *           save/restore prologue and an mret epilogue, so user code can
 *           write the body in plain C.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef NTINY_INIT_H
#define NTINY_INIT_H

/** Disable machine-mode interrupts (clears mstatus.MIE). */
void int_disable(void);

/** Enable machine-mode interrupts (sets mstatus.MIE). */
void int_enable(void);

/* Weak ISR slots. Defined in startup_ntiny.c; override at link time. */
__attribute__((section(".ISR_SOFT_ASM")))
__attribute__((interrupt()))
__attribute__((weak)) void ISR_SOFT_ASM(void);

__attribute__((section(".ISR_EXT_ASM")))
__attribute__((interrupt()))
__attribute__((weak)) void ISR_EXT_ASM(void);

__attribute__((section(".ISR_TIMER_ASM")))
__attribute__((interrupt()))
__attribute__((weak)) void ISR_TIMER_ASM(void);

__attribute__((section(".ISR_DEFAULT_ASM")))
__attribute__((interrupt()))
__attribute__((weak)) void ISR_DEFAULT_ASM(void);

#endif /* NTINY_INIT_H */
