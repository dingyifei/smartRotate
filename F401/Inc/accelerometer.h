/*
 * Copyright (c) 2020-2020, Yifei Ding
 * SPDX-License-Identifier: Apache-2.0

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.

 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied.

 * See the License for the specific language governing permissions and limitations under the License.
 */
#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "MPU6050.h"
extern MPU6050 mpu;
extern int16_t acceleration[3];

void Accel_Init();
void Accel_Update();

#endif //ACCELEROMETER_H
