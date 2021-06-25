#pragma once

#include <Arduino.h>
#include "I_Component.h"

class I2CScanner : I_Component{
public:
    void setup() override;
    void loop() override;

private:

};