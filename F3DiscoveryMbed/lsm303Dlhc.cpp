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
#include "lsm303Dlhc.h"

lsm303Dlhc::lsm303Dlhc(PinName sda, PinName scl, int accAddress, int magAddress) : _i2c(sda, scl) {
    _i2c.frequency(100000);
    addressAcc = accAddress;
    addressMag = magAddress;
}


int lsm303Dlhc::getDevAddr(regAddr addr) const{
    int devAddr;
    if ((addr <= 0x3D) && (addr >= 0x20)) {
        devAddr = addressAcc;
    } else {
        devAddr = addressMag;
    }
    return devAddr;
}


void lsm303Dlhc::write(regAddr addr, char *data, int length) {
    char writeData[50];
    writeData[0] = static_cast<char>((1u << 7u) +
                                     addr); //set MSB to 1 so it automatically increase address when writing
    memcpy(&writeData[1], data, static_cast<size_t>(length));
    _i2c.write(getDevAddr(addr), writeData, length + 1);
}

void lsm303Dlhc::write(regAddr addr, int data) {
    char writeData[2]{static_cast<char>(addr), static_cast<char>(data)};
    _i2c.write(getDevAddr(addr), writeData, 2);
}

void lsm303Dlhc::read(regAddr addr, char *data, int length) {
    char readFromAddr[1];
    readFromAddr[0] = static_cast<char>((1u << 7u) + addr);
    _i2c.write(getDevAddr(addr), readFromAddr, 1);
    _i2c.read(getDevAddr(addr), data, length);
}

void lsm303Dlhc::readAccAxes(int axes[]) {
    char data[6];
    read(OUT_X_L_A, data, 6);
    axes[0] = (int) (data[0] << 8) + data[1];
    axes[1] = (int) (data[2] << 8) + data[3];
    axes[2] = (int) (data[4] << 8) + data[5];
}

void lsm303Dlhc::readMagAxes(int axes[]) {
    char data[6];
    read(OUT_X_L_M, data, 6);
    axes[0] = (int) (data[0] << 8) + data[1];
    axes[1] = (int) (data[2] << 8) + data[3];
    axes[2] = (int) (data[4] << 8) + data[5];
}

void lsm303Dlhc::writeConfig() {
    write(CTRL_REG1_A, config.CTRL_REG1_A);
    write(CTRL_REG2_A, config.CTRL_REG2_A);
    write(CTRL_REG3_A, config.CTRL_REG3_A);
    write(CTRL_REG4_A, config.CTRL_REG4_A);
    write(CTRL_REG5_A, config.CTRL_REG5_A);
    write(CTRL_REG6_A, config.CTRL_REG6_A);
    write(REFERENCE_A, config.REFERENCE_A);
    write(FIFO_CTRL_REG_A, config.FIFO_CTRL_REG_A);
    write(INT1_CFG_A, config.INT1_CFG_A);
    write(INT1_THS_A, config.INT1_THS_A);
    write(INT1_DURATION_A, config.INT1_DURATION_A);
    write(INT2_CFG_A, config.INT2_CFG_A);
    write(INT2_THS_A, config.INT2_THS_A);
    write(INT2_DURATION_A, config.INT2_DURATION_A);
    write(CLICK_CFG_A, config.CLICK_CFG_A);
    write(CLICK_SRC_A, config.CLICK_SRC_A);
    write(CLICK_THS_A, config.CLICK_THS_A);
    write(TIME_LIMIT_A, config.TIME_LIMIT_A);
    write(TIME_LATENCY_A, config.TIME_LATENCY_A);
    write(TIME_WINDOW_A, config.TIME_WINDOW_A);
    write(CRA_REG_M, config.CRA_REG_M);
    write(CRB_REG_M, config.CRB_REG_M);
    write(MR_REG_M, config.MR_REG_M);
}






