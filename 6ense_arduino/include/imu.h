#pragma once

#include <Arduino.h>
#include <I_Component.h>

class Imu : I_Component{
    public:
        void setup() override;
        void loop() override;
    
    private:

};