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
#include "config.h"
#include "GPS.h"

#define SERIAL_BAUDRATE 9600

auto i2c_scanner = I2CScanner();
// auto i2c_scanner = I2CScanner();
SonarCollection sonarCollection = SonarCollection();
// Imu imu = Imu();
GPS gps = GPS();
// Coordinators & Timers:
// Timer timer = Timer("micros");
// Coordinator coordinator = Coordinator(1000); 

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging purposes: to have some time to open the serial monitor.
    
    // Setups:
    Serial.println("Board Type: " + String(BOARD));

    display.setup(display_on);
    imu.setup(imu_on);
    button.setup(button_on);
    sonarCollection.setup(sonar_on);
    gps.setup(gps_on);

    // Coordinator Inits:
    // coordinator.init();
} 

void loop() {
    display.loop(display_on);
    imu.loop(imu_on);
    button.loop(button_on);
    //button.testMe();
    sonarCollection.loop(sonar_on);
    gps.loop(gps_on);

    delay(1000);
}
