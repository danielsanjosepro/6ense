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

};

extern Scorer scorer;