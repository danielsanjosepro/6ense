#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"

class Imu : public I_Component, public I_BTSender {
public:
    // Component Interface
    void setup() override;
    void loop() override;

    // BTSender Interface
    String getData() override;

    // Constructor
    Imu();

private:
    float x, y, z;
    int deg_x = 0;
    int deg_y = 0;

};

extern Imu imu;