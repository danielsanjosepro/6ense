#include "Timer.h"

Timer::Timer(String precision){
    if(precision == "millis"){
        time_now = &millis;
    }else if (precision == "micros"){
        time_now = &micros;
    }else{
        Serial.println("Unknown timing, using millis as default");
        time_now = &millis;
    }
    
}

void Timer::tic(){
    start = (*time_now)();
    toc_counter = 0;
}

long Timer::toc(bool log_duration){
    duration = (*time_now)() - start;
    if(log_duration)
        Serial.println("*Toc* Duration: " + String(duration));
    toc_counter++;
    return duration;
}