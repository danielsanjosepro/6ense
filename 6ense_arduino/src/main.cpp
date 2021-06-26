#include <Arduino.h>
// 6ense includes
// #include "I2CScanner.hpp"
#include "Display.h"
#include "imu.h"

#define SERIAL_BAUDRATE 9600

// auto i2c_scanner = I2CScanner();
auto display = Display(0x27, 16, 2);
auto imu = Imu();

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    // i2c_scanner.setup();
    display.setup();
    imu.setup();
} 

void loop() {
    // i2c_scanner.loop();
    display.loop();
    imu.loop();
}