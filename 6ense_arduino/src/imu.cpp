#include <Arduino_LSM6DS3.h>
#include <imu.h>

float x, y, z;
int deg_x = 0;
int deg_y = 0;


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

        delay(100);




    }
}