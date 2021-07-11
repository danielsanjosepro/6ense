#include "Scorer.h"

Scorer::Scorer(float initScore) : score(initScore), speedScore(initScore), distanceScore(initScore), breakScore(initScore){}

void Scorer::updateScore(){
    //Serial.println("Distance Score: " + String(distanceScore));
    score = (speedScore + distanceScore + breakScore)/3;
}

void Scorer::printScores(){
    Serial.println("General Score: " + String(score));
    Serial.println("------------------------------------");
    Serial.println("Divided into the following subscores:");
    Serial.println("Speed Score: " + String(speedScore));
    Serial.println("Distance Score: " + String(distanceScore));
    Serial.println("Break Score: " + String(breakScore));
    Serial.println("");
}