#include <Arduino.h>

#if defined(ARDUINO_ARDUINO_NANO33BLE)
    #define BOARD "Nano33Ble"
#elif defined(ARDUINO_AVR_UNO)
    #define BOARD "Uno"
#else
    #define BOARD "Nano33IoT"
#endif