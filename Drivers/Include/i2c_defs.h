/*****************************************************************************
 * @file     i2c_defs.h
 * @brief    I2C register offsets (word-indexed) and command codes for NTiny.
 *
 * SPDX-License-Identifier: Apache-2.0
 *****************************************************************************/

#ifndef __I2C__DEFS_H__
#define __I2C__DEFS_H__

#include "ntiny_mem_map.h"

#define REG_CLK_PRESCALER   0x00 /* [15:0] divider value (clk_div - 1)        */
#define REG_CTRL            0x01 /* [7:6] = {i2c_en, interrupt_en}            */
#define REG_RX              0x02 /* [7:0] last byte received                  */
#define REG_STATUS          0x03 /* {rx_ack, busy, arb_lost, ..., tip, irq}   */
#define REG_TX              0x04 /* [7:0] byte to transmit                    */
#define REG_CMD             0x05 /* {start, stop, read, write, ack, _, irqack}*/

#endif /* __I2C__DEFS_H__ */
