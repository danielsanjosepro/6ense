#include "Bluetooth.h"
#include "GPS.h"
#include "Imu.h"
#include "SonarCollection.h"
#include <string>
#include <vector>

//std::vector<I_BTSender> sensors {gps, imu, sonarCollection};  // List of all the sensors we want to send data from
BLEService mainService("0000");  // Main service where all characteristics/sensor data will be advertised
BLEStringCharacteristic gpsCharacteristic("1000",  
    BLERead | BLENotify, 128); 
BLEStringCharacteristic imuCharacteristic("1001",  
    BLERead | BLENotify, 128); 
BLEStringCharacteristic sonarCharacteristic("1002",  
    BLERead | BLENotify, 128);
    
Bluetooth::Bluetooth(): I_Component(){
} 

void Bluetooth::setup(bool bluetoothOn) { 
    Serial.begin(9600);    

    if (!BLE.begin()) {   
        Serial.println("starting BLE failed!");
        while (1);
    }
    
    BLE.setLocalName("Nano33BLE"); 
    BLE.setAdvertisedService(mainService);

    // Here the sensor characteristics need to be added calling the getData method every BTSender has
    // TODO: Make it less ugly and hardcoded by iterating over the list of sensors and their characteristics
    mainService.addCharacteristic(gpsCharacteristic);     
    gpsCharacteristic.setValue(gps.getData());
    mainService.addCharacteristic(imuCharacteristic);
    imuCharacteristic.setValue(imu.getData());
    mainService.addCharacteristic(sonarCharacteristic);
    sonarCharacteristic.setValue(sonarCollection.getData());

    BLE.addService(mainService);
    
    BLE.advertise();  // Start advertising
    Serial.print("Peripheral device MAC: ");
    Serial.println(BLE.address());
    Serial.println("Waiting for connections...");

    BLEDevice central = BLE.central();  // Wait for a BLE central to connect

    // if a central is connected to the peripheral:
    if (central) {
        Serial.print("Connected to central MAC: ");
        Serial.println(central.address());

        if (central.connected()){
            gpsCharacteristic.setValue(gps.getData());    // Values are updated for the first time, after this they get updated in each sensor object
            imuCharacteristic.setValue(imu.getData());
            sonarCharacteristic.setValue(sonarCollection.getData());
        } 
        
        else{
            Serial.print("Disconnected from central MAC: ");
            Serial.println(central.address());
        }

    }
}

void Bluetooth::loop(bool bluetoothOn) {
    // Nothing to do here, everything done by sensors themselves
}