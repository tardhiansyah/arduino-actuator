#include "Actuator.h"

// RELAY CLASS:

Relay::Relay(byte pin)
{
  _pin = pin;
  _activeTime = 0;
  _state = false;
  pinMode(_pin, OUTPUT);
  off();
}

void Relay::alwaysOn()
{
  _state = true;
  digitalWrite(_pin, _state);
}

void Relay::on(uint16_t duration)
{
  _activeTime = millis();
  _duration = duration * 1000;
  _state = true;
  digitalWrite(_pin, _state);
}

void Relay::off()
{
  _activeTime = 0;
  _state = false;
  digitalWrite(_pin, _state);
}

bool Relay::state()
{
  return _state;
}

bool Relay::timeout()
{
  if (_activeTime > 0 && millis() - _activeTime >= _duration)
  {
    off();
    return true;
  }
  return false;
}

uint32_t Relay::activeTime()
{
  return _activeTime;
}


// LED CLASS:

LED::LED(byte pin)
{
  _pin = pin;
  _state = false;
  _interval = 0;
  _lastMillis = 0;

  pinMode(_pin, OUTPUT);
}

void LED::blinkInterval(uint32_t interval)
{
  _interval = interval;
}

void LED::blink()
{
  if (millis() - _lastMillis > _interval)
  {
    _lastMillis = millis();
    _state = !_state;
    digitalWrite(_pin, _state);
  }
}

void LED::on()
{
  _state = true;
  digitalWrite(_pin, _state);
}

void LED::off()
{
  _state = false;
  digitalWrite(_pin, _state);
}