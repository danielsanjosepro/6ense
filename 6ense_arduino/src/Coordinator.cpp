#include "Coordinator.h"

Coordinator::Coordinator(int period_ms) : period(period_ms) {
    timer = Timer("millis");
}

void Coordinator::init(){
    timer.tic();
}

bool Coordinator::allowsLoop(){
    if(timer.toc() > period){
        timer.tic();  // restart timer
        return true;
    } else {
        return false;
        Serial.println("Not hello...");
    }
}