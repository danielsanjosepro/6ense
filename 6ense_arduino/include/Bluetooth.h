#pragma once

#include <Arduino.h>
#include <ArduinoBLE.h>
#include "I_Component.h"

/*BLEService mainService("0000");  // Main service where all characteristics/sensor data will be advertised
BLEStringCharacteristic gpsCharacteristic("1000",  
    BLERead, 13); 
BLEStringCharacteristic imuCharacteristic("1001",  
    BLERead, 13); 
BLEStringCharacteristic sonarCharacteristic("1002",  
    BLERead, 13); */
    
class Bluetooth : public I_Component{
public:
    // Component Interface
    void setup(bool bluetoothOn) override;
    void loop(bool bluetoothOn) override;


    // constructor
    Bluetooth();
};

extern Bluetooth bluetooth;

extern BLEService mainService;
extern BLEStringCharacteristic gpsCharacteristic;
extern BLEStringCharacteristic imuCharacteristic;
extern BLEStringCharacteristic sonarCharacteristic;

