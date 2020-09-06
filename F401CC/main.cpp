#include "mbed.h"
#include "MPU6050.h"
MPU6050 mpu;

DigitalOut led = LED1;
int main()
{
    mpu.initialize();
    mpu.testConnection();
    mpu.setDMPEnabled(true);
    while (true){
        led = !led;
        printf("%i",mpu.getAccelerationX());
        printf("%i",mpu.getAccelerationY());
        printf("%i",mpu.getAccelerationZ());
        thread_sleep_for(1000);
    }

}

