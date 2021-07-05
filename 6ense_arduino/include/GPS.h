#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"
#include <TinyGPS++.h>


class GPS : public I_Component, public TinyGPSPlus, public I_BTSender{
public:
    // Component Interface
    void setup(bool gpsOn) override;
    void loop(bool gpsOn) override;

    // constructor
    GPS();

    // BTSender Interface
    String getData() override;
};

extern GPS gps;