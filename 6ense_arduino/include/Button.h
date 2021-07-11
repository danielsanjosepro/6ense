#pragma once

#include "I_Component.h"
#include <Arduino.h>

class Button : I_Component {
public:
    // Component Interface
    void setup(bool buttonOn) override;
    void loop(bool buttonOn) override;

    // Constructor
    Button(const int pin);

    // Some functions to interact with the button
    bool wasPressedOnce(unsigned long duration = 2000);
    bool wasPressedOnceLong(unsigned long duration = 2000);
    void testMe();

private:
    uint8_t pin;  // should be attached to an interrupt
    
public:
    // debouncing variables (must be public, or at least it makes it easier)
    volatile bool pressed = false;
    volatile bool wasPressed = false;
    volatile uint16_t pressedDuration = 0;
    volatile uint16_t firstTimePressed = 0;
    static const uint8_t debouncingTime = 20;  // milli s
};

extern Button button;