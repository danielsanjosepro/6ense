#include "SonarCollection.h"

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(11, 12));
    sonarVector.push_back(Sonar(2, 3));
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
        delay(500);
    }else{}
}

String SonarCollection::getData(){
    return "Hello World";
}