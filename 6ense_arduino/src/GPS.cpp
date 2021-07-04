#include "GPS.h"

#define GPSSerial Serial1

GPS::GPS(){}

void GPS::setup(bool gps_on=true){
        if(gps_on){
            GPSSerial.begin(9600);
        }else{
            Serial.println("GPS OFF.");
        }
}

void GPS::loop(bool gps_on=true){
    if(gps_on){
        this->encode(GPSSerial.read());
        String lat = String(this->location.lat());
        String lon = String(this->location.lng());
        String speed = String(this->speed.kmph());
        String time = String(this->time.value());
        
        String gpsData = "Lat: " + lat + ", Lon: " + lon + ", Speed: " + speed + ", Time: " + time;
        Serial.println("Data: "+ gpsData);
    }else{}
    
}
