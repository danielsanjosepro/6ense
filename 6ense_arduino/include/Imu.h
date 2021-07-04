#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"


class Imu : public I_Component, public I_BTSender {
public:
    const float sensor_rate=104.00;
    // Component Interface
    void setup(bool imu_on) override;
    void loop(bool imu_on) override;

    Imu();
    // BTSender Interface
    String getData() override;

private:
    float acc_x, acc_y, acc_z; // In units of g 
    float gyro_x, gyro_y, gyro_z; // In units of degrees per sec
    float roll, pitch, yaw; // Orientation angles

};

extern Imu imu;