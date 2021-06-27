#include "Button.h"

/**
 * Interrupt that gets triggered if the button gets pressed.
 * If the button is pressed for the first time (not a bounce)
 * we save the time to estimate how much time the button was
 * pressed.
*/
void ISR_pressed(){
    if(not button.pressed){
        button.pressed = true;
        button.firstTimePressed = millis();
    }
}

/**
 * Interrupt that gets triggered if the button gets unpressed.
 * It deals with the bouncing problem of the button.
*/
void ISR_unpressed(){
    button.pressedDuration = millis() - button.firstTimePressed;
    if(button.pressedDuration > button.debouncingTime){
        button.pressed = false;
        button.wasPressed = true;
    }
}

Button button(2);

Button::Button(int const pin) : pin(pin), pressedDuration(0), firstTimePressed(0){}

void Button::setup(){
    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin), ISR_pressed,  FALLING);
    attachInterrupt(digitalPinToInterrupt(pin), ISR_unpressed, RISING);
    Serial.println("Button: Setup done");
}

void Button::loop(){
    // Nothing to do here
}

/**
 * Returns true if the button was pressed was pressed shortly
 * (less than duration)
 * The argument duration is in milliseconds
 */
bool Button::wasPressedOnce(unsigned long duration){
    if(wasPressed and pressedDuration < duration){
        Serial.println("Duration: " + String(pressedDuration)
        + ", last time pressed: " + String(firstTimePressed)
        + ", millis now: " + String(millis()));
        wasPressed = false;
        pressedDuration = 0;
        return true;
    }else{
        return false;
    }
}

/**
 * Returns true if the button was pressed for a long period of time 
 * (more than duration)
 * The argument duration is in milliseconds
 */
bool Button::wasPressedOnceLong(unsigned long duration){
    if(wasPressed and pressedDuration > duration){
        Serial.println("Duration: " + String(pressedDuration)
        + ", last time pressed: " + String(firstTimePressed)
        + ", millis now: " + String(millis()));
        wasPressed = false;
        pressedDuration = 0;
        return true;
    }else{
        return false;
    }
}
