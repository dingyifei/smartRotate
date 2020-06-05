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
#include "lsm303Dlhc.h"

USBCDC cdc;

// main() runs in its own thread in the OS
int main() {
    printf("hello world");

    lsm303Dlhc LSM303(PB_7, PB_6);


    return 0;
}

