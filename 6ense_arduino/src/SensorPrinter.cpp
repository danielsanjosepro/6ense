#include "SensorPrinter.h"
#include "config.h"
#include "Button.h"
#include "Display.h"
#include "SonarCollection.h"
#include "Imu.h"

SensorPrinter sensorPrinter = SensorPrinter();

void SensorPrinter::setup(bool sensorPrinterOn){
    //nothing to do here
}

void SensorPrinter::loop(bool sensorPrinterOn){
    if(sensorPrinterOn){
        if (shouldPrintSensorValOnDisplay){
            if(button.wasPressedOnce()){
                changeDisplayState();
            }
            printSensorValuesOnDisplay();
        }
    }else{}
}

void SensorPrinter::printSensorValuesOnDisplay(){
    display.clear();
    String sensorValString = "";
    switch (displayState)
    {
        case NONE:
            display.testMe();
            break;
        case SONAR:
            for(auto sonarIt : sonarCollection.sonarVector){
                sensorValString += String(sonarIt.distance);
            }
            display.printSensorValues("Sonar: ", sensorValString);
            break;
        case ACCEL:
            sensorValString = String(imu.accX) + "|"
                            + String(imu.accY) + "|"
                            + String(imu.accZ);
            display.printScore("Accel: ", sensorValString);
            break;
        default:
            break;
    }
}

void SensorPrinter::changeDisplayState(){
    displayState++;
    if(displayState == GO_TO_FIRST)
        displayState = SONAR;
}