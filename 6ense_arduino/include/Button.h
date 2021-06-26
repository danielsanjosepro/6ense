#pragma once

#include "I_Component.h"
#include <Arduino.h>

class Button : I_Component {
public:
    // Component Interface
    void setup() override;
    void loop() override;

    // Constructor
    Button(const int pin);

    // Some functions to interact with the button
    bool wasPressedOnce(unsigned long duration = 1000);
    bool wasPressedOnceLong(unsigned long duration = 1000);

private:
    int pin;  // should be attached to an interrupt

public:
    // debouncing variables (must be public, or at least it makes it easier)
    bool pressed = false;
    bool wasPressed = false;
    unsigned long pressedDuration;
    unsigned long lastTimePressed;
    static const long debouncingTime = 100;  // micro s
};

extern Button button;