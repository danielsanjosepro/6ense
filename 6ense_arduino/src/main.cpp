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
#include "Scorer.h"
#include "SensorPrinter.h"

#define SERIAL_BAUDRATE 9600

auto i2c_scanner = I2CScanner();
// auto i2c_scanner = I2CScanner();
SonarCollection sonarCollection = SonarCollection();
GPS gps = GPS();
Imu imu = Imu();
SensorPrinter sensorPrinter = SensorPrinter();
// Scorer
Scorer scorer = Scorer(100);
// Coordinators & Timers:
Timer timer = Timer("millis");
Coordinator buttonCoordinator =     Coordinator(buttonTime); 
Coordinator displayCoordinator =    Coordinator(displayTime);
Coordinator sonarCoordinator =      Coordinator(sonarTime);
Coordinator imuCoordinator =        Coordinator(imuTime);
Coordinator gpsCoordinator =        Coordinator(gpsTime);
Coordinator scoreCoordinator =      Coordinator(scoreTime);
Coordinator sensorPrintCoordinator= Coordinator(sensorPrintTime);

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);  // start serial communication for other Objects
    delay(5000); // only debugging purposes: to have some time to open the serial monitor.
    
    // Setups:
    Serial.println("Board Type: " + String(BOARD));

    display.setup(displayOn);
    imu.setup(imuOn);
    i2c_scanner.setup(i2cScannerOn);
    button.setup(buttonOn);
    sonarCollection.setup(sonarOn);
    gps.setup(gpsOn);
    sensorPrinter.setup(sensorPrintOn);

    // Coordinator Inits:
    buttonCoordinator.init();
    displayCoordinator.init();
    imuCoordinator.init();
    sonarCoordinator.init();
    gpsCoordinator.init();
    scoreCoordinator.init();
    sensorPrintCoordinator.init();
}

void loop() {
    if(displayCoordinator.allowsLoop())
        display.loop(displayOn);

    if(imuCoordinator.allowsLoop()){
        imu.loop(imuOn);
    }

    i2c_scanner.loop(i2cScannerOn);

    if(buttonCoordinator.allowsLoop())
        button.loop(buttonOn);

    if(sonarCoordinator.allowsLoop()){
        sonarCollection.loop(sonarOn);
    }

    if(gpsCoordinator.allowsLoop())
        gps.loop(gpsOn);

    if(scoreCoordinator.allowsLoop() and scoreOn){
        scorer.updateScore();
        scorer.printScores();
    }

    if(sensorPrintCoordinator.allowsLoop()){
        sensorPrinter.loop(sensorPrintOn);
    }

}
