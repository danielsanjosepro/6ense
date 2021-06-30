#pragma once

#include <Arduino.h>
#include "Timer.h"

/**
 *  Coordinators schedule the loop time for every object in the loop.
 *  Usage:
 *  imuCoordinator(100);  // the imu will be called every 100 ms
 *  ...
 *  if(imuCoordinator.allowsLoop())
 *      imu.loop()
*/
class Coordinator {
public:
    Coordinator(int period_ms);

    void init();
    bool allowsLoop();
private:
    int period;
    Timer timer;
};