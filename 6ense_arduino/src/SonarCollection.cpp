#include "SonarCollection.h"

int leftTrig = 7, leftEcho = 8, rightTrig = 9, rightEcho = 10, frontTrig = 11, frontEcho = 12;

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(leftTrig,  leftEcho));
    sonarVector.push_back(Sonar(rightTrig,  rightEcho));
    sonarVector.push_back(Sonar(frontTrig, frontEcho));
}

void SonarCollection::setup(bool sonarOn=true){
    if(sonarOn){
        int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.print(String(i)+": ");
            sonarIt.setup(sonarOn);
            i++;
        }
        delay(2000);
    }else{
        Serial.println("SonarCollection OFF.");
    }
   
}

void SonarCollection::loop(bool sonarOn=true){
    if(sonarOn){
        /*int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.print(String(i)+": ");
            sonarIt.loop(sonarOn);
            i++;
        }*/
        sonarCharacteristic.writeValue(getData());
    }else{}
}

String SonarCollection::getData(){
    //TODO: characteristics format for sonar data.
    String sonarData = "";
    for (auto sonar : sonarVector){
        sonarData = sonarData + " " + String(sonar.updateDistance());
    }
    return sonarData;
}