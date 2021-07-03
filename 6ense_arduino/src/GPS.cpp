#include "GPS.h"

#define GPSSerial Serial1

GPS::GPS(){}

void GPS::setup(){
    GPSSerial.begin(9600);
}

void GPS::loop(){
    this->encode(GPSSerial.read());
    String lat = String(this->location.lat());
    String lon = String(this->location.lng());
    String speed = String(this->speed.kmph());
    String time = String(this->time.value());
    
    String gpsData = "Lat: " + lat + ", Lon: " + lon + ", Speed: " + speed + ", Time: " + time;
    Serial.println("Data: "+ gpsData);
}
