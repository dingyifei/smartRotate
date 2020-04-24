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
#include "USBCDC.h"
#include "L3GD20.h"


USBCDC cdc;

// main() runs in its own thread in the OS
int main() {
    SPI spi(PA_7, PA_6, PA_5);
    DigitalOut cs(PE_3);
    cs = 1;
    spi.format(8, 3);
    spi.frequency(10000000);

}

