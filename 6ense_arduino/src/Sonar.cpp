#include "Sonar.h"
#include "Display.h"
#include "Button.h"

// Sonar sonar(11, 12);  // only if one sonar is used

Sonar::Sonar(int trigPin, int echoPin):
    trigPin(trigPin), echoPin(echoPin) {}

void Sonar::setup(bool sonarOn=true) {
    if(sonarOn){
        pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
        pinMode(echoPin, INPUT); // Sets the echoPin as an Input
        Serial.println("Sonar: Setup done: trigPin: " + String(trigPin) + ", echoPin: " 
                       + String(echoPin) + ", soundSpeed: " + String(soundSpeed));
    }else{
        Serial.println("Sonar OFF.");
        }
}

void Sonar::loop(bool sonarOn=true) {
    if(sonarOn){
        updateDistance();
        Serial.println(distance);
    }else{}
}

void Sonar::sendTrigPulse(){
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}

/**
 * This function sends a trigger and waits for a response 
 * in the echo pin. If the distance is out of range, it 
 * returns -1.
*/
int Sonar::updateDistance(){
    // Sends a trigger
    sendTrigPulse();
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);  // in ms
    // Calculating the distance
    int measuredDistance = duration * (soundSpeed/2);
    if(outOfRange(measuredDistance)){
        return distance = -1;
    }
    return distance = measuredDistance;
}

/**
 * Judges if the distance is valid
*/
bool Sonar::outOfRange(int distance){
    return distance > maxDistance;
}

void Sonar::printDistanceOnDisplay(){
    display.setCursor(0,0);
    display.print("Distance:" + String(distance) + " cm");
}