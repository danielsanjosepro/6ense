#pragma once
#include <Arduino.h>

/*
 *  Timer objects are used to time events/processes.
 *  Usage:
 *  Timer timer("millis");     
 *  timer.tic();
 *  delay(2000);
 *  Serial.println(timer.toc()); // 2000
 */
class Timer {
public:
    Timer(String precision = "millis");

    // main functions: tic() to restart the timer, toc() to get the time
    void tic();
    uint16_t toc(bool logDuration=false);

private:
    uint16_t start = 0;
    uint16_t duration = 0;
    uint16_t tocCounter = 0;
    unsigned long int (*timeNow)();
};