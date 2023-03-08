#include "LED.h"

LED::LED(byte pin)
{
  _pin = pin;
  _state = false;
  _interval = 0;
  _lastMillis = 0;

  pinMode(_pin, OUTPUT);
}

void LED::setBlinkInterval(uint32_t interval)
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