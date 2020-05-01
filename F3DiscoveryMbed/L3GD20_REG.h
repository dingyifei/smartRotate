/*
Copyright (c) 2020-2020, Yifei Ding
SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.

You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
either express or implied.

See the License for the specific language governing permissions and limitations under the License.
*/

#ifndef F3DISCOVERYMBED_L3GD20_REG_H
#define F3DISCOVERYMBED_L3GD20_REG_H

#define L3GD20_REG_WHO_AM_I 0x0F
#define L3GD20_REG_CTRL_REG1 0x20
#define L3GD20_REG_CTRL_REG2 0x21
#define L3GD20_REG_CTRL_REG3 0x22
#define L3GD20_REG_CTRL_REG4 0x23
#define L3GD20_REG_CTRL_REG5 0x24
#define L3GD20_REG_REFERENCE 0x25
#define L3GD20_REG_OUT_TEMP 0x26
#define L3GD20_REG_STATUS_REG 0x27
#define L3GD20_REG_OUT_X_L 0x28
#define L3GD20_REG_OUT_X_H 0x29
#define L3GD20_REG_OUT_Y_L 0x2A
#define L3GD20_REG_OUT_Y_H 0x2B
#define L3GD20_REG_OUT_Z_L 0x2C
#define L3GD20_REG_OUT_Z_H 0x2D
#define L3GD20_REG_FIFO_CTRL_REG 0x2E
#define L3GD20_REG_FIFO_SRC_REG 0x2F
#define L3GD20_REG_INT1_CFG 0x30
#define L3GD20_REG_INT1_SRC 0x31
#define L3GD20_REG_INT1_THS_X_H 0x32
#define L3GD20_REG_INT1_THS_X_L 0x33
#define L3GD20_REG_INT1_THS_Y_H 0x34
#define L3GD20_REG_INT1_THS_Y_L 0x35
#define L3GD20_REG_INT1_THS_Z_H 0x36
#define L3GD20_REG_INT1_THS_Z_L 0x37
#define L3GD20_REG_INT1_DURATION 0x38

#define L3GD20_REG_READ 0b10000000
#define L3GD20_REG_WRITE 0b00000000
#define L3GD20_REG_MULTIPLE_READ_WRITE 0b01000000

#endif //F3DISCOVERYMBED_L3GD20_REG_H


