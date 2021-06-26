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
    // i2c_scanner.setup();
    //display.setup();
} 

void loop() {
    // i2c_scanner.loop();
    //display.loop();
    if(button.wasPressedOnce()){
        Serial.println("The button was pressed once shortly");
    }else if(button.wasPressedOnceLong()){
        Serial.println("The button was pressed once for more than 1 second");
    }else{
        Serial.println("The button was not pressed");
    }
    delay(500);
}