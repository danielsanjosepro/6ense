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

long Timer::toc(){
    duration = (*time_now)() - start;
    Serial.write("*Toc* Duration: " + duration);
    toc_counter++;
    return duration;
}