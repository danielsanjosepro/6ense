#include <Arduino_LSM6DS3.h>
#include <Imu.h>
#include "MadgwickAHRS.h"

// TODO: Test if madwick filter is to slow
Madgwick filter; // Init madwick filter

Imu::Imu() : I_BTSender(3) {} // 3 for each axis

void Imu::setup(bool imuOn=true){
    if(imuOn){
    while(!Serial);
    Serial.println("Started IMU");

    if(!IMU.begin()){
        Serial.println("Failed to initialize IMU.");
    }
    filter.begin(imu.sensorRate);
    }else{
        Serial.println("IMU OFF.");
    }
}


void Imu::loop(bool imuOn=true){
    if(imuOn){
        if(IMU.accelerationAvailable() && 
            IMU.gyroscopeAvailable()){
                IMU.readAcceleration(accX, accY, accZ);
                IMU.readGyroscope(gyroX, gyroY, gyroZ);

                filter.updateIMU(gyroX, gyroY, gyroZ, accX, accY, accZ);   

                roll = filter.getRoll();
                pitch = filter.getPitch();
                yaw = filter.getYaw();

                imuCharacteristic.writeValue(getData());
        }
    }else{}
        
    
    
            
    
}

// TODO: Characteristics format for imu data
String Imu::getData(){
    String imuData = "accX: "  + String(accX)  + "\t" 
                    + "accY: "  + String(accY)  + "\t" 
                    + "accZ: "  + String(accZ)  + "\n"
                    + "gyroX: " + String(gyroX) + "\t"
                    + "gyroY: " + String(gyroY) + "\t"
                    + "gyroZ: " + String(gyroZ) + "\n"
                    + "roll: "   + String(roll)   + "\t"
                    + "pitch: "  + String(pitch)  + "\t"
                    + "yaw: "    + String(yaw)    + "\n";

    return imuData;
}

extern Imu imu;