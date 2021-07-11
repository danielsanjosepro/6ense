#include "GPS.h"

#define GPSSerial Serial1

GPS::GPS() : I_BTSender(4) {} // latitude, longitude, velocity, time

void GPS::setup(bool gpsOn=true){
        if(gpsOn){
            GPSSerial.begin(9600);
        }else{
            Serial.println("GPS OFF.");
        }
}

void GPS::loop(bool gpsOn=true){
    if(gpsOn){
        String gpsData = this->getData();
        Serial.println("Data: "+ gpsData);

        updateScore();
    }else{}
}

String GPS::getData(){
    this->encode(GPSSerial.read());
    String lat = String(this->location.lat());
    String lon = String(this->location.lng());
    String speed = String(this->speed.kmph());
    String time = String(this->time.value());
        
    String gpsData = "Lat: " + lat + ", Lon: " + lon + ", Speed: " + speed + ", Time: " + time;

    return gpsData;
}

//TODO: Add threasholds through config
void GPS::updateScore(){
    // this->encode(GPSSerial.read());
    uint8_t speed = this->speed.kmph()-25;
    if (speed > 0){
        scorer.speedScore -= speed;
        if (scorer.speedScore < 0){
            scorer.speedScore = 0;
        }
    }
}


