#include "SonarCollection.h"

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(7, 8));
    sonarVector.push_back(Sonar(9, 10));
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
        int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.print(String(i)+": ");
            sonarIt.loop(sonarOn);
            i++;
        }
    }else{}
}

String SonarCollection::getData(){
    //TODO: characteristics format for sonar data.
    return "Data is coming.";
}