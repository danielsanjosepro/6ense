#include "SonarCollection.h"

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(11, 12));
    sonarVector.push_back(Sonar(2, 3));
}

void SonarCollection::setup(){
    int i = 1;  // only for debugging purposes
    for(auto sonarIt : sonarVector){
        Serial.print(String(i)+": ");
        sonarIt.setup();
        i++;
    }
    delay(2000);
}

void SonarCollection::loop(){
    int i = 1;  // only for debugging purposes
    for(auto sonarIt : sonarVector){
        Serial.print(String(i)+": ");
        sonarIt.loop();
        i++;
    }
    delay(500);
}

String SonarCollection::getData(){
    return "Hello World";
}