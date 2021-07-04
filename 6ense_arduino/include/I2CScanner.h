#pragma once

#include <Arduino.h>
#include "I_Component.h"

class I2CScanner : I_Component{
public:
    void setup(bool i2c_scanner_on) override;
    void loop(bool i2c_scanner_on) override;

private:

};