/*****************************************************************************
 * @file     plic_defs.h
 * @brief    PLIC register offsets (word-indexed) for the NTiny SoC.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef PLIC_DEFS_H_
#define PLIC_DEFS_H_

#include "ntiny_mem_map.h"

#define IE_INTERRUPT  0x00 /*!< RW: per-source enable mask (bit per IRQ ID)  */
#define THRESHOLD     0x01 /*!< RW: priority threshold (only IRQs > T fire)  */
#define PRIORITY      0x02 /*!< RW: per-source priority encoding             */
#define INTERRUPT_ID  0x03 /*!< RO: read claims the highest-priority pending */

#endif /* PLIC_DEFS_H_ */
