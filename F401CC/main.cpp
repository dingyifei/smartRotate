#include "mbed.h"
#include "MPU6050.h"
MPU6050 mpu;

DigitalOut led = LED1;
string s;
int16_t x, y, z;
int main()
{
    mpu.initialize();
    mpu.setDMPEnabled(true);

    while (true){
        thread_sleep_for(100);
        x = mpu.getRotationX();
        y = mpu.getRotationY();
        z = mpu.getRotationZ();
        s = to_string(x+y+z);
        if(s == "helloworld"){
            led = true;
        }
    }

}

