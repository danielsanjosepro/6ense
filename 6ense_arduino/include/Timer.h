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
    long toc(bool log_duration=false);

private:
    long start = 0;
    long duration = 0;
    int toc_counter = 0;
    unsigned long (*time_now)();
};