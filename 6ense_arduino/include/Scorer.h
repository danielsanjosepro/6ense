#pragma once

#include <Arduino.h>

class Scorer{
    public:
    // Some parameters for the display of the score
    enum displayStates {
        NONE =          0,
        GLOBAL =        1,
        SPEED =         2,
        DISTANCE =      3,
        BREAK =         4,
        GO_TO_GLOBAL =  5
    };
   uint8_t displayState = NONE;

    // TODO: Turn these into Setter and Getter functions with private/protected score variables
    void updateScore();
    void printScores();

    // Display Printing methods
    void changeDisplayState();
    void printScoresOnDisplay();

    //Constructor 
    Scorer(float initScore);

    float score;
    float speedScore;
    float distanceScore;
    float breakScore;

};

extern Scorer scorer;