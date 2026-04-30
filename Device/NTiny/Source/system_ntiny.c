/*****************************************************************************
 * @file     system_ntiny.c
 * @brief    CMSIS-style system initialisation for the NTiny SoC.
 * @version  1.0.0
 *
 *           SystemInit() is invoked by the reset handler before main(). It
 *           is the right place for any one-shot configuration that should
 *           happen on every boot but that is not part of the bring-up
 *           assembly stub: enabling the FPU at the C level, priming the
 *           SystemCoreClock variable, and so on.
 *
 *           SystemCoreClockUpdate() is provided so application code can
 *           refresh SystemCoreClock after changing the core clock via PLL
 *           or any platform-specific control register. The default NTiny
 *           build runs at a fixed 50 MHz, so the implementation is trivial.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#include "ntiny.h"
#include "ntiny_config.h"

/** Default core clock for the taped-out NTiny SoC. */
#define NTINY_DEFAULT_HCLK    F_CPU

/** Visible to user code; updated by SystemCoreClockUpdate(). */
uint32_t SystemCoreClock = NTINY_DEFAULT_HCLK;

void SystemCoreClockUpdate(void)
{
    /* The NTiny core has no PLL or programmable clock divider in the
     * current revision, so the runtime frequency is the build-time one. */
    SystemCoreClock = NTINY_DEFAULT_HCLK;
}

void SystemInit(void)
{
    /* The reset handler already enabled mstatus.FS in assembly, but doing
     * it again here keeps the contract self-contained for callers who
     * invoke SystemInit() after a soft reset. */
    csr_set(mstatus, NTINY_MSTATUS_FS);

    SystemCoreClockUpdate();
}
