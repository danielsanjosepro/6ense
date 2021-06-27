#include <Arduino.h>

#if defined(ARDUINO_ARDUINO_NANO33BLE)
    #define BOARD "Nano33Ble"
#else
    #define BOARD "Nano33IoT"
#endif