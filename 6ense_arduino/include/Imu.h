#pragma once

#include <Arduino.h>
#include <tuple>
#include "I_Component.h"
#include "I_BTSender.h"
#include <iostream>


class Imu : public I_Component, public I_BTSender {
public:
    float sensor_rate; // In units of Hz
    unsigned long time_current; // Current time since arduino started for velocity calculation
    unsigned long time_last = 0.00; // Last timestamp since velocity calculation
    // Component Interface
    void setup() override;
    void loop() override;

    // BTSender Interface
    String getData() override;

    // Constructor
    Imu(const float& sensor_rate);

    // Function to compute velocity for delta t from the accelerometers component's
    std::tuple<float, unsigned long> compute_current_velocity(float& velocity_last, 
                                                              const float& acc, 
                                                              unsigned long& time_last){
        float dv = 0;
        float velocity = 0;
        time_current = millis();

        dv = acc * (time_current - time_last);
        velocity = dv + velocity_last; // Combine velocity from last timestep with new one
        time_last = time_current;

        return std::make_tuple(velocity, time_last);
    }


private:
    float acc_x, acc_y, acc_z; // In units of g 
    float gyro_x, gyro_y, gyro_z; // In units of degrees per sec
    float roll, pitch, yaw; // Orientation angles
    float velocity_x = 0.0; // Inital velocity
    float velocity_y = 0.0;
    float velocity_z = 0.0;

};

extern Imu imu;