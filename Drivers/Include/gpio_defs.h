/*****************************************************************************
 * @file     gpio_defs.h
 * @brief    GPIO register offsets (word-indexed) for the NTiny SoC.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef GPIO_DEFS_H_
#define GPIO_DEFS_H_

#include "ntiny_mem_map.h"

/*
 * GPIO register layout. The driver indexes a (uint32_t *) at the GPIO base
 * address using these offsets, so each value is a word index, not a byte.
 *   0x0 DDR  : data-direction (1 = output, 0 = input)
 *   0x1 Dout : data-output
 *   0x2 Din  : data-input  (read-only)
 *   0x3 cmd  : command register -- write strobes for reset and IRQ control
 */
#define DDR     0x0000
#define Dout    0x0001
#define Din     0x0002
#define cmd     0x0003

#endif /* GPIO_DEFS_H_ */
