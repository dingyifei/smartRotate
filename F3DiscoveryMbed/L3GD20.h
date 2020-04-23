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

#ifndef F3DISCOVERYMBED_L3GD20_H
#define F3DISCOVERYMBED_L3GD20_H
#include "mbed.h"
#include "L3GD20_REG.h"
struct l3gd20StartupConfig{
    int CTRL_REG2;
    int CTRL_REG3;
    int CTRL_REG4;
    int CTRL_REG5;
    int REFERENCE;
    int INT1_THS_XH;
    int INT1_THS_XL;
    int INT1_THS_YH;
    int INT1_THS_YL;
    int INT1_THS_ZH;
    int INT1_THS_ZL;
    int INT1_CFG;
    int CTRL_REG1;
};


int readL3gd20(SPI*, DigitalOut*, int, int*);
int writeL3gd20(SPI *L3GD20, DigitalOut *cs, int REG, int data);
int startL3gd20(SPI *L3GD20, DigitalOut *cs, l3gd20StartupConfig startupConfig);
#endif //F3DISCOVERYMBED_L3GD20_H
