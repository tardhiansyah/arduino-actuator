#include "Relay.h"

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