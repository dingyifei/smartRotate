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
#include "mbed.h"

#ifndef F3DISCOVERYMBED_LSM303DLHC_H
#define F3DISCOVERYMBED_LSM303DLHC_H
enum regAddr {
// read-write
    CTRL_REG1_A = 0x20,
    CTRL_REG2_A = 0x21,
    CTRL_REG3_A = 0x22,
    CTRL_REG4_A = 0x23,
    CTRL_REG5_A = 0x24,
    CTRL_REG6_A = 0x25,
    REFERENCE_A = 0x26,
    FIFO_CTRL_REG_A = 0x2E,
    INT1_CFG_A = 0x30,
    INT1_THS_A = 0x32,
    INT1_DURATION_A = 0x33,
    INT2_CFG_A = 0x34,
    INT2_THS_A = 0x36,
    INT2_DURATION_A = 0x37,
    CLICK_CFG_A = 0x38,
    CLICK_SRC_A = 0x39,
    CLICK_THS_A = 0x3A,
    TIME_LIMIT_A = 0x3B,
    TIME_LATENCY_A = 0x3C,
    TIME_WINDOW_A = 0x3D,
    CRA_REG_M = 0x00,
    CRB_REG_M = 0x01,
    MR_REG_M = 0x02,
// read only
    STATUS_REG_A = 0x27,
    OUT_X_L_A = 0x28,
    OUT_X_H_A = 0x29,
    OUT_Y_L_A = 0x2A,
    OUT_Y_H_A = 0x2B,
    OUT_Z_L_A = 0x2C,
    OUT_Z_H_A = 0x2D,
    FIFO_SRC_REG_A = 0x2F,
    INT1_SRC_A = 0x31,
    INT2_SRC_A = 0x35,
    OUT_X_H_M = 0x03,
    OUT_X_L_M = 0x04,
    OUT_Z_H_M = 0x05,
    OUT_Z_L_M = 0x06,
    OUT_Y_H_M = 0x07,
    OUT_Y_L_M = 0x08,
    SR_REG_M = 0x09,
    IRA_REG_M = 0x0A,
    IRB_REG_M = 0x0B,
    IRC_REG_M = 0x0C
};


class lsm303Dlhc {
    struct configuration {
        int CTRL_REG1_A = 0b00000111;
        int CTRL_REG2_A = 0b00000000;
        int CTRL_REG3_A = 0b00000000;
        int CTRL_REG4_A = 0b00000000;
        int CTRL_REG5_A = 0b00000000;
        int CTRL_REG6_A = 0b00000000;
        int REFERENCE_A = 0b00000000;
        int FIFO_CTRL_REG_A = 0b00000000;
        int INT1_CFG_A = 0b00000000;
        int INT1_THS_A = 0b00000000;
        int INT1_DURATION_A = 0b00000000;
        int INT2_CFG_A = 0b00000000;
        int INT2_THS_A = 0b00000000;
        int INT2_DURATION_A = 0b00000000;
        int CLICK_CFG_A = 0b00000000;
        int CLICK_SRC_A = 0b00000000;
        int CLICK_THS_A = 0b00000000;
        int TIME_LIMIT_A = 0b00000000;
        int TIME_LATENCY_A = 0b00000000;
        int TIME_WINDOW_A = 0b00000000;
        int CRA_REG_M = 0b00010000;
        int CRB_REG_M = 0b00100000;
        int MR_REG_M = 0b00000011;
    };
public:

    lsm303Dlhc(PinName sda, PinName scl, int accAddress = 0b00110010, int magAddress = 0b00111100);

    void write(regAddr addr, char *data, int length);

    void write(regAddr addr, int data);

    void read(regAddr addr, char data[], int length);

    void writeConfig();

    void readAccAxes(int axes[3]);

    void readMagAxes(int axes[3]);

    struct configuration config;
    I2C _i2c;
private:
    int getDevAddr(regAddr addr) const;


    int addressAcc;
    int addressMag;
};


#endif //F3DISCOVERYMBED_LSM303DLHC_H
