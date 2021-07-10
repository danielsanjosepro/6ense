#include "Timer.h"

Timer::Timer(String precision){
    if(precision == "millis"){
        timeNow = &millis;
    }else if (precision == "micros"){
        timeNow = &micros;
    }else{
        Serial.println("Unknown timing, using millis as default");
        timeNow = &millis;
    }
    
}

void Timer::tic(){
    start = (*timeNow)();
    tocCounter = 0;
}

uint16_t Timer::toc(bool logDuration){
    duration = (*timeNow)() - start;
    if(logDuration)
        Serial.println("*Toc* Duration: " + String(duration));
    tocCounter++;
    return duration;
}