#include <Arduino_LSM6DS3.h>
#include <Imu.h>

Imu::Imu() : I_BTSender(3) {} // 3 for each axis

void Imu::setup(){
    while(!Serial);
    Serial.println("Started IMU");

    if(!IMU.begin()){
        Serial.println("Failed to initialize IMU.");
    }
}


void Imu::loop(){
    if(IMU.accelerationAvailable()){
        IMU.readAcceleration(x, y, z);
        Serial.print("x: " + String(x) + "\t");
        Serial.print("y: " + String(y) + "\t");
        Serial.print("z: " + String(z) + "\n");
    }
}

String Imu::getData(){
    return "Hello!";  // TODO 
}