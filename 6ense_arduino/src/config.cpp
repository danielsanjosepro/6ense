#include "config.h"
/**
 * @brief Config file for setup variables and testing
 */

bool displayOn =       true;
bool imuOn =           false;
bool buttonOn =        true;
bool sonarOn =         true;
bool gpsOn =           false;
bool i2cScannerOn =    false;
bool bluetoothOn =     false;

char16_t displayTime =  1000; 
char16_t imuTime =      1000;
char16_t buttonTime =   1000;
char16_t sonarTime =    2000;
char16_t gpsTime =      100;
char16_t scoreTime =    2000;

// Score parameters
bool shouldPrintScoresOnDisplay =     true;
bool shouldPrintSensorValOnDisplay =  false;
 
float speedWeight =             1;
float distanceWeight =          1;
float breakWeight =             1;

// distance parameters
char criticalDistance =         10;
float distanceImportance =      2.0;

// other Parameters
float criticalSpeed =           0.0;
float criticalAccel =           0.0;

