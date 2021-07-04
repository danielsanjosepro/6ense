#include "SonarCollection.h"

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(7, 8));
    sonarVector.push_back(Sonar(9, 10));
}

void SonarCollection::setup(bool sonar_on=true){
    if(sonar_on){
        int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.print(String(i)+": ");
            sonarIt.setup(sonar_on);
            i++;
        }
        delay(2000);
    }else{
        Serial.println("SonarCollection OFF.");
    }
   
}

void SonarCollection::loop(bool sonar_on=true){
    if(sonar_on){
        int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.print(String(i)+": ");
            sonarIt.loop(sonar_on);
            i++;
        }
    }else{}
}

String SonarCollection::getData(){
    return "Hello World";
}