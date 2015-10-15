#ifndef BUTTONLISTENER_H
#define BUTTONLISTENER_H

#include "../framework/Continual.h"
#include "OnPressCallable.h"

class ButtonListener : public Continual
{

private:
  byte _inpin;
  bool _state;
  bool PRESSED;
  OnPressCallable *_onPress;

protected:
  void work(long now)
  {
    bool b = digitalRead(_inpin);
    //wenn _state changes
    if(_state != b)
    {
      _state = b;

      if(_state == PRESSED)
      {
        Serial.println(">ButtonListener< pressed");
        _onPress->onPress();
      }
      else //RELEASED
      {
        //Serial.println("released");
        //TODO
      }
    }
  }

public:

  ButtonListener(byte id, long pace, byte inpin, OnPressCallable* onPressClbl)
  : Continual(id, pace), _onPress(onPressClbl)
    {
      setInpin(inpin);
      _state = digitalRead(_inpin);
      PRESSED = !_state;
    }

  inline void setInpin(byte inpin)
  {
    _inpin = inpin;
    pinMode(_inpin, INPUT);
  }

  inline byte getInpin()
  {
    return _inpin;
  }

};

#endif //BUTTONLISTENER_H