// Includes Arduino.h and Macros for the board type
#include "BoardDetect.h"

// 6ense includes
// #include "I2CScanner.hpp"
#include "Display.h"
#include "Imu.h"
#include "Button.h"

#define SERIAL_BAUDRATE 9600

Imu imu = Imu();

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging: purposes to have some time to open the serial monitor.
    
    // Setups:
    // i2c_scanner.setup();
    Serial.println("Board Type: " + String(BOARD));
    display.setup();
    imu.setup();
    button.setup();
} 

void loop() {
    // i2c_scanner.loop();
    display.loop();
    imu.loop();
    button.loop();
    button.testMe();
    delay(500);
}
