#include "Bluetooth.h"
#include "GPS.h"
#include "Imu.h"
#include <string>
#include <vector>

Bluetooth bluetooth = Bluetooth();

std::vector<I_BTSender*> sensors {&gps, &imu};

Bluetooth::Bluetooth(): I_Component(){
} 

BLEService mainService("0000");  // User defined service
BLEStringCharacteristic gpsCharacteristic("1000",  // standard 16-bit characteristic UUID
    BLERead, 13); // remote clients will only be able to read this
BLEStringCharacteristic imuCharacteristic("1001",  // standard 16-bit characteristic UUID
    BLERead, 13); // remote clients will only be able to read this

void Bluetooth::setup(bool bluetooth_on) {
  Serial.begin(9600);    // initialize serial communication

  if (!BLE.begin()) {   // initialize BLE
    Serial.println("starting BLE failed!");
    while (1);
  }
  
  BLE.setLocalName("Nano33BLE");  // Set name for connection
  BLE.setAdvertisedService(mainService);

  mainService.addCharacteristic(gpsCharacteristic);
  gpsCharacteristic.setValue(gps.getData());
  mainService.addCharacteristic(imuCharacteristic);
  imuCharacteristic.setValue(imu.getData());

  BLE.addService(mainService);
  
  BLE.advertise();  // Start advertising
  Serial.print("Peripheral device MAC: ");
  Serial.println(BLE.address());
  Serial.println("Waiting for connections...");
}


void Bluetooth::loop(bool bluetooth_on) {
  BLEDevice central = BLE.central();  // Wait for a BLE central to connect

  // if a central is connected to the peripheral:
  if (central) {
    Serial.print("Connected to central MAC: ");
    // print the central's BT address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    digitalWrite(LED_BUILTIN, HIGH);

    while (central.connected()){
      gpsCharacteristic.setValue(gps.getData());
      imuCharacteristic.setValue(imu.getData());
    } // keep looping while connected
    
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central MAC: ");
    Serial.println(central.address());
  }
}