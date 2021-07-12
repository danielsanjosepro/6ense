#include "config.h"
/**
 * @brief Config file for setup variables and testing
 */

bool displayOn =       true;
bool imuOn =           true;
bool buttonOn =        true;
bool sonarOn =         true;
bool gpsOn =           false;
bool i2cScannerOn =    false;
bool bluetoothOn =     false;

bool scoreOn =         true;
bool sensorPrintOn =   true;

char16_t displayTime =      1000; 
char16_t imuTime =          100;
char16_t buttonTime =       100;
char16_t sonarTime =        500;
char16_t gpsTime =          1000;
char16_t scoreTime =        2000;
char16_t sensorPrintTime =  2000;

// Score parameters
bool shouldPrintScoresOnDisplay =     false;
bool shouldPrintSensorValOnDisplay =  true;

float speedWeight =             1;
float distanceWeight =          1;
float breakWeight =             1;

// distance parameters
char criticalDistance =         10;
float distanceImportance =      2.0;

// Acceleration parameters
float criticalAccel =           1.2;
float accelImportance =         2.0;

// gps parameters
float criticalSpeed =           0.0;

long waitingTimeToIncreaseScore = 5000;
float increaseScoreWeight = 2.5;
