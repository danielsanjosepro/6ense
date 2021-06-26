#pragma once

#include "I_Component.h"
#include <LiquidCrystal_I2C.h>

class Display : I_Component, LiquidCrystal_I2C {
public:
    // Component Interface
    void setup() override;
    void loop() override;

    void testMe();

    // constructor
    Display(const int i2c_addr, const int num_columns, const int num_lines);

    //LiquidCrystal_I2C lcd;

private:
    uint8_t logo[8] = {
	0b00011,
	0b00100,
	0b01000,
	0b10000,
	0b11110,
	0b10001,
	0b10001,
	0b01110
    };
};

extern Display display;