#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"
#include <TinyGPS++.h>


class GPS : public I_Component, public TinyGPSPlus, public I_BTSender{
public:
    // Component Interface
    void setup(bool gps_on) override;
    void loop(bool gps_on) override;

    // constructor
    GPS();

    // BTSender Interface
    String getData() override;
};

extern GPS gps;