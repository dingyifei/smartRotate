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
struct l3Gd20StartupConfig{
    int ctrlReg2 = 0b00000000;
    int ctrlReg3 = 0b00000000;
    int ctrlReg4 = 0b00000000;
    int ctrlReg5 = 0b00000000;
    int reference = 0b00000000;
    int int1ThsXh = 0b00000000;
    int int1ThsXl = 0b00000000;
    int int1ThsYh = 0b00000000;
    int int1ThsYl = 0b00000000;
    int int1ThsZh = 0b00000000;
    int int1ThsZl = 0b00000000;
    int int1Duration = 0b00000000;
    int int1Cfg = 0b00000000;
    int ctrlReg1 = 0b00000111;
};
struct l3Gd20Out{
    int xL;
    int xH;
    int yL;
    int yH;
    int zL;
    int zH;
};
int readL3Gd20(SPI *, DigitalOut *, int, int *);
int writeL3Gd20(SPI *, DigitalOut *, int, int);
int startL3Gd20(SPI *, DigitalOut *, l3Gd20StartupConfig);
int readL3Gd20Axis(SPI *, DigitalOut*, l3Gd20Out*);
#endif //F3DISCOVERYMBED_L3GD20_H
