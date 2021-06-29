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

    // Function to compute velocity for delta t from the accelerometers component's
    float compute_current_velocity(float& velocity_last, const float& acc, 
                                   float& time_current, float& time_last){
        float dv = 0;
        float velocity = 0;
        
        dv = acc * (time_current - time_last);
        velocity = dv + velocity_last;
        time_last = time_current;

        return velocity;
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