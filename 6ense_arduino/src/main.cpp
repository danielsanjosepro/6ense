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

    //Debugging:
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
} 

void loop() {
    // i2c_scanner.loop();

    display.loop();
    button.loop();

    if(button.wasPressedOnce()){
        Serial.println("The button was pressed once shortly");
    }else if(button.wasPressedOnceLong()){
        Serial.println("The button was pressed once for more than 1 second");
    }else{
        Serial.println("The button was not pressed");
    }
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(500);
}
