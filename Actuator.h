#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>

class LED
{
  public:
    LED(byte pin);

    void blinkInterval(uint32_t interval);
    void blink();
    void on();
    void off();

  private:
    byte _pin;
    uint32_t _interval;
    uint32_t _lastMillis;
    bool _state;
};

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