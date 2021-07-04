#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include <TinyGPS++.h>


class GPS : public I_Component, public TinyGPSPlus{
public:
    // Component Interface
    void setup() override;
    void loop() override;

    // constructor
    GPS();
};

extern GPS gps;