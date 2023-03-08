#ifndef LED_ARDUINO_H
#define LED_ARDUINO_H

#include <Arduino.h>

class LED
{
  public:
    LED(byte pin);

    void setBlinkInterval(uint32_t interval);
    void blink();
    void on();
    void off();

  private:
    byte _pin;
    uint32_t _interval;
    uint32_t _lastMillis;
    bool _state;
};

#endif