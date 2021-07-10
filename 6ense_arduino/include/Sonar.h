#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"

class Sonar : public I_Component {
public:
    // Component Interface
    void setup(bool sonarOn) override;
    void loop(bool sonarOn) override;

    //Constructor 
    Sonar(int trigPin, int echoPin);

    // "API": some functions to use the Sonar module
    uint16_t updateDistance();  // TODO could be uint8
    void printDistanceOnDisplay();

private:
    // Pin Numbers
    uint8_t trigPin;
    uint8_t echoPin;

    // Variables used in computations:
    uint16_t duration = 0;
    uint16_t distance = 0;
    uint16_t maxDistance = 300; // cm
    const float soundSpeed = 0.034;  // TODO other data type for this

    // Some functions for internal use
    void sendTrigPulse();
    bool outOfRange(uint16_t distance);
};

// extern Sonar sonar;  // only if 1 Sonar is used