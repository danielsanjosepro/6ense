#pragma once

#include <Arduino.h>
#include <I_Component.h>

class Imu : I_Component{
public:
    void setup() override;
    void loop() override;
    
private:
    float x, y, z;
    int deg_x = 0;
    int deg_y = 0;

};

extern Imu imu;