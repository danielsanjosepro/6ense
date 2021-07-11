#include "Display.h"

Display display(0x27, 16, 2);

Display::Display(const int i2cAddr, const int numColumns, const int numLines) 
    : LiquidCrystal_I2C(i2cAddr, numColumns, numLines) {}

void Display::setup(bool displayOn=true){
    if(displayOn){
        this->init();                      
        this->backlight();
        this->createChar(0, logo);
        // test the  LCD:
        testMe();
        Serial.println("Display: Setup done");
    }else{
        Serial.println("Display OFF.");
    }
    
}

void Display::loop(bool displayOn=true) {
    if(displayOn) {} else{}
}

void Display::testMe(){
    this->setCursor(2, 0);
    this->write(0);
    this->setCursor(3, 0);
    this->print("ense: safety");
    this->setCursor(3, 1);
    this->print("for drivers");
}

void Display::printSensorValues(String sensorName, String sensorValue){
    this->clear();
    this->setCursor(0, 0);
    this->print(sensorName);
    this->setCursor(0, 1);
    this->print(sensorValue);
}

void Display::printScore(String scoreName, String scoreValue){
    this->clear();
    this->setCursor(0, 0);
    this->print(scoreName);
    this->setCursor(0, 1);
    this->print("-> "+scoreValue);
}