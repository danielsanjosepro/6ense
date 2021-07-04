#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include "I_BTSender.h"
#include <iostream>
#include <tuple>


class Imu : public I_Component, public I_BTSender {
public:
    float sensor_rate; // In units of Hz
    unsigned long time_current; // Current time since arduino started for velocity calculation
    unsigned long time_last = 0.00; // Last timestamp since velocity calculation
    // Component Interface
    void setup(bool imu_on) override;
    void loop(bool imu_on) override;

    // BTSender Interface
    String getData() override;


    // Constructor
    Imu(const float& sensor_rate);


private:
    float acc_x, acc_y, acc_z; // In units of g 
    float gyro_x, gyro_y, gyro_z; // In units of degrees per sec
    float roll, pitch, yaw; // Orientation angles

};

extern Imu imu;