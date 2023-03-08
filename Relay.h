#ifndef RELAY_ARDUINO_H
#define RELAY_ARDUINO_H

#include <Arduino.h>

class Relay
{
  public:
    Relay(byte pin);

    void alwaysOn();
    void off();
    void on(uint16_t duration);
    bool state();
    bool timeout();
    uint32_t activeTime();

  private:
    byte _pin;
    uint32_t _activeTime;
    uint32_t _duration;
    bool _state;
};

#endif