#pragma once

#include <Arduino.h>
#include "I_Component.h"

class SensorPrinter : public I_Component {
public:
    // Some parameters for the display sensor values
    enum displayStates {
        NONE =          0,
        SONAR =         1,
        ACCEL =         2,
        GO_TO_FIRST =   3,
        // GPS
    };   
   uint8_t displayState = NONE;
    // Component Interface
    void setup(bool sensorPrinterOn) override;
    void loop(bool sensorPrinterOn) override;   

    void changeDisplayState();
    void printSensorValuesOnDisplay();
};

extern SensorPrinter sensorPrinter;