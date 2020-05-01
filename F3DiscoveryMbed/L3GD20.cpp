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
#include "L3GD20.h"

int readL3Gd20(SPI *l3Gd20, DigitalOut *cs, int reg, int *data) {
    l3Gd20->lock();
    *cs = 0;
    l3Gd20->write(reg + L3GD20_REG_READ);
    *data = l3Gd20->write(0x00);
    *cs = 1;
    l3Gd20->unlock();
    return 0;
}

int writeL3Gd20(SPI *l3Gd20, DigitalOut *cs, int reg, int data) {
    l3Gd20->lock();
    *cs = 0;
    l3Gd20->write(reg + L3GD20_REG_WRITE);
    l3Gd20->write(data);
    *cs = 1;
    l3Gd20->unlock();
    return 0;
}

int startL3Gd20(SPI *l3Gd20, DigitalOut *cs, l3Gd20Config startupConfig) {
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_CTRL_REG2, startupConfig.ctrlReg2);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_CTRL_REG3, startupConfig.ctrlReg3);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_CTRL_REG4, startupConfig.ctrlReg4);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_CTRL_REG5, startupConfig.ctrlReg5);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_REFERENCE, startupConfig.reference);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_H, startupConfig.int1ThsXh);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_L, startupConfig.int1ThsXl);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_H, startupConfig.int1ThsYh);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_L, startupConfig.int1ThsYl);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_H, startupConfig.int1ThsZh);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_THS_X_L, startupConfig.int1ThsZl);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_DURATION, startupConfig.int1Duration);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_INT1_CFG, startupConfig.int1Cfg);
    writeL3Gd20(l3Gd20, cs, L3GD20_REG_CTRL_REG1, startupConfig.ctrlReg1);
    return 0;
}

int readL3Gd20Axis(SPI* l3Gd20, DigitalOut* cs, l3Gd20Out* output){
    int status, low, high;
    readL3Gd20(l3Gd20, cs, L3GD20_REG_STATUS_REG, &status);
    while(status-0b11011111==0b00100000){
        readL3Gd20(l3Gd20, cs, L3GD20_REG_STATUS_REG, &status);
        if(status-0b11011111==0){
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_H,&high);
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_L,&low);
            output->x = static_cast<int16_t>((low) | (high << 8));
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_H,&high);
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_L,&low);
            output->y = static_cast<int16_t>((low) | (high << 8));
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_H,&high);
            readL3Gd20(l3Gd20, cs, L3GD20_REG_OUT_X_L,&low);
            output->z = static_cast<int16_t>((low) | (high << 8));
            break;
        }
    }
    return 0;
}

