#include "Button.h"

void ISR_pressed(){
    button.pressed = true;
    button.lastTimePressed = millis();
}
void ISR_unpressed(){
    button.pressedDuration = millis() - button.lastTimePressed;
    if(button.pressedDuration > button.debouncingTime){
        button.pressed = false;
        button.wasPressed = true;
    }
}

Button button(2);

Button::Button(int const pin) : pin(pin), pressedDuration(0), lastTimePressed(0){}

void Button::setup(){
    pinMode(pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pin), ISR_pressed,  FALLING);
    attachInterrupt(digitalPinToInterrupt(pin), ISR_unpressed, RISING);
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
        wasPressed = false;
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
bool Button::wasPressedOnceLong(unsigned long duration ){
    if(wasPressed and pressedDuration > duration){
        wasPressed = false;
        return true;
    }else{
        return false;
    }
}
