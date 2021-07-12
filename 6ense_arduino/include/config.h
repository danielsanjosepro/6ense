
/**
 * @brief Config file for setup variables and testing
 */
#ifndef __config_h__
#define __config_h__

extern bool displayOn;
extern bool imuOn;
extern bool buttonOn;
extern bool sonarOn;
extern bool gpsOn;
extern bool i2cScannerOn;
extern bool bluetoothOn;

extern bool scoreOn;
extern bool sensorPrintOn;

extern char16_t displayTime; 
extern char16_t imuTime;
extern char16_t buttonTime;
extern char16_t sonarTime;
extern char16_t gpsTime;
extern char16_t scoreTime;
extern char16_t sensorPrintTime;

// Score parameters
extern bool shouldPrintScoresOnDisplay;
extern bool shouldPrintSensorValOnDisplay;

extern float speedWeight;
extern float distanceWeight;
extern float breakWeight;
extern float totalWeight;

// distance parameters
extern char criticalDistance;
extern float distanceImportance; 
// gps Parameters
extern float criticalSpeed;
// accel Parameters
extern float criticalAccel;
extern float accelImportance;

#endif