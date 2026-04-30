/*****************************************************************************
 * @file     system_ntiny.h
 * @brief    CMSIS-style system header for the NTiny RV32IMAFC SoC.
 * @version  1.0.0
 * @date     2026-04-30
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef SYSTEM_NTINY_H
#define SYSTEM_NTINY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** Trap handler function pointer type. */
typedef void (*VECTOR_TABLE_Type)(void);

/**
 * @brief  Current core clock frequency in Hz.
 *
 * Updated by SystemCoreClockUpdate(); user code may read this directly.
 * Defaults to NTINY_DEFAULT_HCLK (50 MHz).
 */
extern uint32_t SystemCoreClock;

/**
 * @brief  One-time system initialisation.
 *
 * Called from the reset handler before main(). Configures mtvec, enables
 * the FPU (mstatus.FS = Initial), and updates SystemCoreClock.
 */
extern void SystemInit(void);

/**
 * @brief  Refresh SystemCoreClock from the current CPU configuration.
 */
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_NTINY_H */
