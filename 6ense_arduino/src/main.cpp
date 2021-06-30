// Includes Arduino.h and Macros for the board type
#include "BoardDetect.h"

// 6ense includes
#include "I2CScanner.h"
#include "Display.h"
#include "Imu.h"
#include "Button.h"
#include "I_BTSender.h"
#include "Sonar.h"
#include "SonarCollection.h"
#include "Timer.h"
#include "Coordinator.h"

#define SERIAL_BAUDRATE 9600

// auto i2c_scanner = I2CScanner();
SonarCollection sonarCollection = SonarCollection();
Imu imu = Imu();

// Coordinators & Timers:
// Timer timer = Timer("micros");
// Coordinator coordinator = Coordinator(1000); 

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging purposes: to have some time to open the serial monitor.
    
    // Setups:
    Serial.println("Board Type: " + String(BOARD));
    // i2c_scanner.setup();
    // display.setup();
    // imu.setup();
    // button.setup();
    // sonar.setup();
    // sonarCollection.setup();

    // Coordinator Inits:
    // coordinator.init();
} 

void loop() {
    // i2c_scanner.loop();
    // display.loop();
    // imu.loop();
    // button.loop();
    // button.testMe();
    // sonar.loop();
    // sonarCollection.loop();
}
