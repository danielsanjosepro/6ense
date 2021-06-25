#include <Arduino.h>
// 6ense includes
// #include "I2CScanner.hpp"
#include "Display.h"

#define SERIAL_BAUDRATE 9600

// auto i2c_scanner = I2CScanner();
auto display = Display(0x27, 16, 2);

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    // i2c_scanner.setup();
    display.setup();
} 

void loop() {
    // i2c_scanner.loop();
    display.loop();
}