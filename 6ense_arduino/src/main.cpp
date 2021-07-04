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
GPS gps = GPS();
Imu imu = Imu();
// Coordinators & Timers:
Timer timer = Timer("millis");
Coordinator buttonCoordinator =     Coordinator(buttonTime); 
Coordinator displayCoordinator =    Coordinator(displayTime);
Coordinator sonarCoordinator =      Coordinator(sonarTime);
Coordinator imuCoordinator =        Coordinator(imuTime);
Coordinator gpsCoordinator =        Coordinator(gpsTime);

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging purposes: to have some time to open the serial monitor.
    
    // Setups:
    Serial.println("Board Type: " + String(BOARD));

    display.setup(display_on);
    imu.setup(imu_on);
    i2c_scanner.setup(i2c_scanner_on);
    button.setup(button_on);
    sonarCollection.setup(sonar_on);
    gps.setup(gps_on);

    // Coordinator Inits:
    buttonCoordinator.init();
    displayCoordinator.init();
    imuCoordinator.init();
    sonarCoordinator.init();
    gpsCoordinator.init();
} 

void loop() {
    if(displayCoordinator.allowsLoop())
        display.loop(display_on);

    if(imuCoordinator.allowsLoop()){
        timer.tic();
        imu.loop(imu_on);
        timer.toc(true);
    }

    i2c_scanner.loop(i2c_scanner_on);

    if(buttonCoordinator.allowsLoop())
        button.loop(button_on);

    if(sonarCoordinator.allowsLoop()){
        timer.tic();
        sonarCollection.loop(sonar_on);
        timer.toc(true);
    }
    if(gpsCoordinator.allowsLoop())
        gps.loop(gps_on);

}
