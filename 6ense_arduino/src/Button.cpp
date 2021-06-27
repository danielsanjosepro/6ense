#include "Button.h"

/**
 * Interrupt that gets triggered if the button changes.
 * If the button is pressed for the first time (not a bounce)
 * we save the time to estimate how much time the button was
 * pressed.
*/
void ISR_buttonChange(){
    if(!button.pressed){  // first time that the button is pressed
        button.pressed = true;
        button.firstTimePressed = millis();
    }else{
        button.pressedDuration = millis() - button.firstTimePressed;
        if(button.pressed and button.pressedDuration > button.debouncingTime){
            button.pressed = false;
            button.wasPressed = true;
        }
    }
}

Button button(2);

Button::Button(int const pin) : pin(pin), pressedDuration(0), firstTimePressed(100){}

void Button::setup(){
    pinMode(pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin), ISR_buttonChange, CHANGE);
    Serial.println("Button: Setup done");
}

void Button::testMe(){
    if(button.wasPressedOnce()){
        Serial.println("The button was pressed once shortly");
    }else if(button.wasPressedOnceLong()){
        Serial.println("The button was pressed once for more than 2 seconds");
    }else{
        Serial.println("The button was not pressed");
    }
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
    if(wasPressed && (pressedDuration < duration)){
        Serial.println("Duration: " + String(pressedDuration)
        + ", first time pressed: " + String(firstTimePressed)
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
    if(wasPressed && (pressedDuration > duration)){
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
