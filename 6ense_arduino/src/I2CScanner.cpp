#include "I2CScanner.h"
#include <Wire.h>

void I2CScanner::setup(bool i2c_scanner_on=true){
    Serial.println();
    Serial.println("I2C scanner. Scanning ...");
    byte count = 0;

    Wire.begin();
    delay(5000);
    for (byte i = 8; i < 120; i++){
        Wire.beginTransmission(i);
        if (Wire.endTransmission() == 0){
            Serial.print("Found address: ");
            Serial.print(i, DEC);
            Serial.print(" (0x");
            Serial.print(i, HEX);
            Serial.println(")");
            count++;
            delay(1); // maybe unneeded?
        }             // end of good response
    }                 // end of for loop
    Serial.println("Done.");
    Serial.print("Found ");
    Serial.print(count, DEC);
    Serial.println(" device(s).");
}

void I2CScanner::loop(bool i2c_scanner_on=true) {}
