#include <Arduino.h>

// 6ense includes
// #include "I2CScanner.hpp"
#include "Display.h"
#include "Button.h"

#define SERIAL_BAUDRATE 9600

// auto i2c_scanner = I2CScanner();

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging: purposes to have some time to open the serial monitor.
    
    // Setups:
    // i2c_scanner.setup();
    display.setup();
    button.setup();
} 

void loop() {
    // i2c_scanner.loop();

    display.loop();
    button.loop();
}
