#include <Arduino_LSM6DS3.h>
#include <Imu.h>
#include "MadgwickAHRS.h"
#include <iostream>



Imu::Imu(const float& sensor_rate) : I_BTSender(3) {} // 3 for each axis
Imu imu(104.00);

void Imu::setup(){
    while(!Serial);
    Serial.println("Started IMU");

    if(!IMU.begin()){
        Serial.println("Failed to initialize IMU.");
    }
}


void Imu::loop(){
    if(IMU.accelerationAvailable() && 
       IMU.gyroscopeAvailable()){
        IMU.readAcceleration(acc_x, acc_y, acc_z);
        IMU.readGyroscope(gyro_x, gyro_y, gyro_z);

        // Serial.print("x: " + String(acc_x) + "\t");
        // Serial.print("y: " + String(acc_y) + "\t");
        // Serial.print("z: " + String(acc_z) + "\n");
        
        // Test velocity for one axis
        auto velocity_x = imu.velocity_x;
        std::tie(velocity_x, time_last) = imu.compute_current_velocity(velocity_x, acc_x, time_last);
    }
}

String Imu::getData(){
    return "Hello!";  // TODO 
}