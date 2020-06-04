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
#include "LSM303DLHC.h"

LSM303DLHC::LSM303DLHC(I2C *interface, int accAddress, int magAddress) {
    LSM303DLHC_i2c = interface;
    LSM303DLHC_address_acc = accAddress;
    LSM303DLHC_address_mag = magAddress;

}

int LSM303DLHC::getDevAddr(regAddr addr) {
    int devAddr;
    if (addr <= 0x3D && addr >= 0x20) {
        devAddr = LSM303DLHC_address_acc;
    } else {
        devAddr = LSM303DLHC_address_mag;
    }
    return devAddr;
}

void LSM303DLHC::write(regAddr addr, char *data, int length) {
    char writeData[50];
    writeData[0] = (1u << 7u) + addr; //set MSB to 1 so it automatically increase address when writing
    memcpy(&writeData[1], data, length);
    LSM303DLHC_i2c->write(getDevAddr(addr), writeData, length + 1);
}

void LSM303DLHC::read(regAddr addr, char *data, int length) {
    char readFromAddr[1];
    readFromAddr[0] = (1u << 7u) + addr;
    LSM303DLHC_i2c->write(getDevAddr(addr), readFromAddr, 1);
    LSM303DLHC_i2c->read(getDevAddr(addr), data, length);
}

void LSM303DLHC::readAccAxes(int axes[]) {
    char data[6];
    read(OUT_X_L_A, data, 6);
    axes[0] = (int) (data[0] << 8) + data[1];
    axes[1] = (int) (data[2] << 8) + data[3];
    axes[2] = (int) (data[4] << 8) + data[5];
}

void LSM303DLHC::readMagAxes(int axes[]) {
    char data[6];
    read(OUT_X_L_M, data, 6);
    axes[0] = (int) (data[0] << 8) + data[1];
    axes[1] = (int) (data[2] << 8) + data[3];
    axes[2] = (int) (data[4] << 8) + data[5];
}





