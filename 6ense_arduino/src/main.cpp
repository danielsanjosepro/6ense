#include <Arduino.h>

#if defined(ARDUINO_ARDUINO_NANO33BLE)
    #define BOARD "Nano33Ble"
#else
    #define BOARD "Nano33IoT"
#endif

// 6ense includes
// #include "I2CScanner.hpp"
#include "Display.h"
#include "imu.h"
#include "Button.h"

#define SERIAL_BAUDRATE 9600

// auto i2c_scanner = I2CScanner();
auto imu = Imu();

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging: purposes to have some time to open the serial monitor.
    
    // Setups:
    // i2c_scanner.setup();
    Serial.println("Board Type: " + String(BOARD));
    display.setup();
    // imu.setup();
    button.setup();
} 

void loop() {
    // i2c_scanner.loop();
    display.loop();
    // imu.loop();
    button.loop();
    button.testMe();
    delay(500);
}
