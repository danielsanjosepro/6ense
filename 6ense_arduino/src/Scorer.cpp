#include "Scorer.h"
#include "Button.h"
#include "Display.h"
#include "config.h"

Scorer::Scorer(float initScore) : score(initScore), speedScore(initScore), distanceScore(initScore), breakScore(initScore){}

void Scorer::setup(bool scoreOn){
    if(scoreOn){
        distanceTimer.tic();
        breakTimer.tic();
    }else{}
}

void Scorer::loop(bool scoreOn){
    if(scoreOn){
        updateScore();
        printScores();
    }else{}
}

void Scorer::updateScore(){
    //Serial.println("Distance Score: " + String(distanceScore));
    score = (speedScore + distanceScore + breakScore)/3;

    // Check if score is decreasing
    // if(oldSpeedScore - speedScore > 1.0)
    if(oldDistanceScore - distanceScore > 1.0)
        distanceTimer.tic();
    if(oldBreakScore - breakScore > 1.0)
        breakTimer.tic();
    // Check if the score should increase
    if(breakTimer.toc() > waitingTimeToIncreaseScore and breakScore < 100.0)
        breakScore += increaseScoreWeight;
    if(distanceTimer.toc() > waitingTimeToIncreaseScore and distanceScore < 100.0)
        distanceScore += increaseScoreWeight;
    // if(speedTimer.toc() > waitingTimeToIncreaseScore)
    //     breakScore += increaseScoreWeight;

    // update scores
    oldDistanceScore = distanceScore;
    oldBreakScore = breakScore;
    oldSpeedScore = speedScore;
}

void Scorer::printScores(){
    if(shouldPrintScoresOnDisplay){
        if(button.wasPressedOnce()){
            changeDisplayState();
        }
        printScoresOnDisplay();
    }else{
        Serial.println("====================================");
        Serial.println("General Score: " + String(score));
        Serial.println("------------------------------------");
        Serial.println("Divided into the following subscores:");
        Serial.println("Speed Score: " + String(speedScore));
        Serial.println("Distance Score: " + String(distanceScore));
        Serial.println("Break Score: " + String(breakScore));
        Serial.println("");
    }
}

void Scorer::changeDisplayState(){
    displayState++;
    if(displayState == GO_TO_GLOBAL){
        displayState = GLOBAL;
    }
}

void Scorer::printScoresOnDisplay(){
    display.clear();
    switch (displayState)
    {
        case NONE:
            display.testMe();
            break;
        case GLOBAL:
            display.printScore("Global Score", String(score));
            break;
        case SPEED:
            display.printScore("Speed Score", String(speedScore));
            break;
        case DISTANCE:
            display.printScore("Distance Score", String(distanceScore));
            break;
        case BREAK:
            display.printScore("Break Score", String(breakScore));
            break;
        default:
            break;
    }
}