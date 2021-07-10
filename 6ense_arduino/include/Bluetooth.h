#pragma once

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "I_Component.h"

class Bluetooth : public I_Component{
public:
    // Component Interface
    void setup(bool bluetoothOn) override;
    void loop(bool bluetoothOn) override;

    // constructor
    Bluetooth();
};

extern Bluetooth bluetooth;