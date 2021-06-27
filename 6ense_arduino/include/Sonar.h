#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"

#include <ArduinoSTL.h>

class Sonar : public I_Component {
public:
    // Component Interface
    void setup() override;
    void loop() override;

    //Constructor 
    Sonar(int trigPin, int echoPin);

    // "API": some functions to use the Sonar module
    int updateDistance();
    void printDistanceOnDisplay();

private:
    // Pin Numbers
    int trigPin;
    int echoPin;

    // Variables used in computations:
    long duration = 0;
    long distance = 0;
    long maxDistance = 1000; // cm
    const float soundSpeed = 0.034; 

    // Some functions for internal use
    void sendTrigPulse();
    bool outOfRange(int distance);
};

// extern Sonar sonar;  // only if 1 Sonar is used