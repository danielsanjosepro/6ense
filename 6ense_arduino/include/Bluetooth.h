#pragma once

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "I_Component.h"

class Bluetooth : public I_Component{
public:
    // Component Interface
    void setup(bool bluetooth_on) override;
    void loop(bool bluetooth_on) override;

    // constructor
    Bluetooth();
};

extern Bluetooth bluetooth;