#include <Arduino_LSM6DS3.h>
#include <Imu.h>
#include "MadgwickAHRS.h"
#include <iostream>

// TODO: Test if madwick filter is to slow
Madgwick filter; // Init madwick filter

Imu::Imu(const float& sensor_rate) : I_BTSender(3) {} // 3 for each axis
Imu imu(104.00); // Init with 104 Hz sensor rate

void Imu::setup(bool imu_on=true){
    if(imu_on){
    while(!Serial);
    Serial.println("Started IMU");

    if(!IMU.begin()){
        Serial.println("Failed to initialize IMU.");
    }
    filter.begin(imu.sensor_rate);
    }else{
        Serial.println("IMU OFF.");
    }
}


void Imu::loop(bool imu_on=true){
    if(imu_on){
        if(IMU.accelerationAvailable() && 
           IMU.gyroscopeAvailable()){
               IMU.readAcceleration(acc_x, acc_y, acc_z);
               IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
               
               filter.updateIMU(gyro_x, gyro_y, gyro_z, acc_x, acc_y, acc_z);   
               
               roll = filter.getRoll();
               pitch = filter.getPitch();
               yaw = filter.getYaw();

               String imu_data = imu.getData();
               Serial.println(imu_data);
               delay(500);
        }
    }else{}
    
    
            
    
}

// TODO: Bug in roll, pitch and yaw
String Imu::getData(){
    String imu_data = "acc_x: "  + String(acc_x)  + "\t" 
                    + "acc_y: "  + String(acc_y)  + "\t" 
                    + "acc_z: "  + String(acc_z)  + "\n"
                    + "gyro_x: " + String(gyro_x) + "\t"
                    + "gyro_y: " + String(gyro_y) + "\t"
                    + "gyro_z: " + String(gyro_z) + "\n"
                    + "roll: "   + String(roll)   + "\t"
                    + "pitch: "  + String(pitch)  + "\t"
                    + "yaw: "    + String(yaw)    + "\n";

    return imu_data;
}