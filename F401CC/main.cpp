#include <USBHID.h>
#include "mbed.h"
#include "MPU6050.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

MPU6050 mpu;

DigitalOut led = LED1;

USBHID usbHid(true,
              64,
              64,
              0x1234,
              0x0006,
              0x0001);

HID_REPORT output_report = {
    .length = 64,
    .data = {0}
};

HID_REPORT input_report = {
    .length = 64,
    .data = {0}
};

int main()
{
    mpu.initialize();
    mpu.setDMPEnabled(true);
    while (true) {
        // Fill the report
        for (int i = 0; i < output_report.length; i++) {
            output_report.data[i] = rand() & UINT8_MAX;
        }

        // Send the report
        usbHid.send(&output_report);

        // Try to read a msg
        if (usbHid.read_nb(&input_report)) {
            led = !led;
            for (int i = 0; i < input_report.length; i++) {
                printf("%d ", input_report.data[i]);
            }
            printf("\r\n");
        }
    }
}


#pragma clang diagnostic pop