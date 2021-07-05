#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"


class Imu : public I_Component, public I_BTSender {
public:
    const float sensorRate=104.00;
    // Component Interface
    void setup(bool imuOn) override;
    void loop(bool imuOn) override;

    Imu();
    // BTSender Interface
    String getData() override;

private:
    float accX, accY, accZ; // In units of g 
    float gyroX, gyroY, gyroZ; // In units of degrees per sec
    float roll, pitch, yaw; // Orientation angles

};

extern Imu imu;