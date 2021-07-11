#pragma once

#include <Arduino.h>

class Scorer{
    public:
    // TODO: Turn these into Setter and Getter functions with private/protected score variables
    void updateScore();
    void printScores();

    //Constructor 
    Scorer(float initScore);

    float score;
    float speedScore;
    float distanceScore;
    float breakScore;

};

extern Scorer scorer;