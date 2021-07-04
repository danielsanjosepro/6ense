#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include <TinyGPS++.h>


class GPS : public I_Component, public TinyGPSPlus{
public:
    // Component Interface
    void setup(bool gps_on) override;
    void loop(bool gps_on) override;

    // constructor
    GPS();
};

extern GPS gps;