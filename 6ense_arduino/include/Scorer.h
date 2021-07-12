#pragma once

#include <Arduino.h>
#include  <I_Component.h>
#include <Timer.h>

class Scorer : public I_Component {
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
    // Component Interface
    void setup(bool scoreOn) override;
    void loop(bool scoreOn) override;   

    // TODO: Turn these into Setter and Getter functions with private/protected score variables
    void updateScore();
    void printScores();

    // Display Printing methods
    void changeDisplayState();
    void printScoresOnDisplay();

    //Constructor 
    Scorer(float initScore);

    // Timer to increase the score
    Timer distanceTimer = Timer();
    Timer breakTimer    = Timer();

    float score;

    float speedScore;
    float oldSpeedScore = 100.0;

    float distanceScore;
    float oldDistanceScore = 100.0;

    float breakScore;
    float oldBreakScore = 100.0;

};

extern Scorer scorer;