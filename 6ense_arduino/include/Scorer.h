#pragma once

#include <Arduino.h>

class Scorer{
    public:
    // Setter function
    void updateScore(uint8_t update);

    //Constructor 
    Scorer();

    private:
    uint8_t score;
    uint8_t speedScore;
    uint8_t breakScore;
    uint8_t distanceScore;

};

extern Scorer scorer;