#include <Arduino.h>

class Timer {
public:
    Timer(String precision = "millis");

    // main functions: tic() to restart the timer, toc() to get the time
    void tic();
    long toc();

private:
    long start = 0;
    long duration = 0;
    int toc_counter = 0;
    unsigned long (*time_now)();
};