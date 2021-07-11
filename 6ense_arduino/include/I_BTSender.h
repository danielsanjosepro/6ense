#pragma once

#include <Arduino.h>
#include "Scorer.h"

class I_BTSender {  // theoretically not an Interface but almost
public:
    virtual String getData() = 0;
    virtual void updateScore() = 0;
    uint8_t numOfCharacteristics;

    // Constructor
    I_BTSender(int numOfCharacteristics);
};

/*
CODE EXAMPLE WITH VECTORS AND THIS BASE CLASS TYPE:
    #include <vector>

    std::vector<I_BTSender*> my_vector;
    my_vector.emplace_back(&imu);
    // my_vector.emplace_back(&sonar);
    for(auto &obj : my_vector){
        Serial.println(obj->numOfCharacteristics);
    }
*/