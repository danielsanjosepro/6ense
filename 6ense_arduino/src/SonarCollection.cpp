#include "SonarCollection.h"

#include "config.h"

SonarCollection::SonarCollection() : I_BTSender(1) {
    sonarVector.push_back(Sonar(8, 7));
    sonarVector.push_back(Sonar(10, 9));
    sonarVector.push_back(Sonar(12, 11));
}

void SonarCollection::setup(bool sonarOn=true){
    if(sonarOn){
        int i = 1;  // only for debugging purposes
        for(auto sonarIt : sonarVector){
            Serial.println(String(i)+": ");
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

    updateScore();
    }else{}
}

String SonarCollection::getData(){
    //TODO: characteristics format for sonar data.
    return "Data is coming.";
}

//TODO: Add threashold and weight to config
void SonarCollection::updateScore(){
    for (auto sonar:sonarVector){
        if(sonar.updateDistance() < criticalDistance){
            scorer.distanceScore -= distanceImportance * (criticalDistance-float(sonar.updateDistance()))/criticalDistance;
            if (scorer.distanceScore < 0){
                scorer.distanceScore = 0;
            }
            //Serial.println("Distance Score is now: " + String(scorer.distanceScore));
        }
    }
}