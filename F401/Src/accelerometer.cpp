//TODO: PUT MY COPY RIGHT HERE
#include "accelerometer.h"

MPU6050 mpu;
void Accel_Init(){
  mpu.initialize(); //Init MPU6050
  if(mpu.testConnection()){ //Operational indicator
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
  }
}



