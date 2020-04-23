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

int readL3gd20(SPI *L3GD20, DigitalOut *cs, int REG, int *data) {
    L3GD20->lock();
    *cs = 0;
    L3GD20->write(REG + L3GD20_REG_READ);
    *data = L3GD20->write(0x00);
    *cs = 1;
    L3GD20->unlock();
    return 0;
}

int writeL3gd20(SPI *L3GD20, DigitalOut *cs, int REG, int data) {
    L3GD20->lock();
    *cs = 0;
    L3GD20->write(REG + L3GD20_REG_WRITE);
    L3GD20->write(data);
    *cs = 1;
    L3GD20->unlock();
    return 0;
}

int startL3gd20(SPI *L3GD20, DigitalOut *cs, l3gd20StartupConfig startupConfig){
    writeL3gd20(L3GD20, cs, L3GD20_REG_CTRL_REG2, startupConfig.CTRL_REG2);
    writeL3gd20(L3GD20, cs, L3GD20_REG_CTRL_REG3, startupConfig.CTRL_REG3);
    writeL3gd20(L3GD20, cs, L3GD20_REG_CTRL_REG4, startupConfig.CTRL_REG4);
    writeL3gd20(L3GD20, cs, L3GD20_REG_CTRL_REG5, startupConfig.CTRL_REG5);
    writeL3gd20(L3GD20, cs, L3GD20_REG_REFERENCE, startupConfig.REFERENCE);
    writeL3gd20(L3GD20, cs, L3GD20_REG_INT1_THS_XH, startupConfig.INT1_THS_XH);
    writeL3gd20(L3GD20, cs, L3GD20_REG_INT1_THS_XL, startupConfig.INT1_THS_XL);


}
