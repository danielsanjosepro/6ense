#pragma once

#include <Arduino.h>
#include "I_Component.h"
#include <LiquidCrystal_I2C.h>

class Display : public I_Component, public LiquidCrystal_I2C {
public:
    // Component Interface
    void setup(bool displayOn) override;
    void loop(bool displayOn) override;

    void testMe();
    void printSensorValues(String sensorName, String sensorValue);
    void printScore(String scoreName, String scoreValue);

    // constructor
    Display(const int i2cAddr, const int numColumns, const int numLines);

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