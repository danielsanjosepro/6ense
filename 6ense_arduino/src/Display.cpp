#include "Display.h"

Display::Display(const int i2c_addr, const int num_columns, const int num_lines) 
    : LiquidCrystal_I2C(i2c_addr, num_columns, num_lines) {}

void Display::setup(){
    this->init();                      
    this->backlight();
    this->createChar(0, logo);
    // test the  LCD:
    testMe();
}

void Display::loop() {
    // nothing to do for now
}

void Display::testMe(){
    this->setCursor(2, 0);
    this->write(0);
    this->setCursor(3, 0);
    this->print("ense: safety");
    this->setCursor(3, 1);
    this->print("for drivers");
}