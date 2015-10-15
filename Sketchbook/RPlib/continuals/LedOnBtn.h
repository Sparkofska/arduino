#ifndef LEDONBTN_H
#define LEDONBTN_H

#include "../button/OnPressCallable.h"

class LedOnBtn : public OnPressCallable
{

private:
  byte _outpin;
  bool _state;

public:
  LedOnBtn(byte outpin)
     : _state(false)
    {
      setOutpin(outpin);
    };

  inline void onPress()
  {
    Serial.println(">LedOnBtn< onPress");
    _state = !_state;
    digitalWrite(_outpin, _state ? HIGH : LOW);
  }

  inline void onRelease()
  {
    Serial.println(">LedOnBtn< onRelease");
    //no op
  }

  inline void setOutpin(byte outpin)
  {
    _outpin = outpin;
    pinMode(_outpin, OUTPUT);
  }

  inline byte getOutpin()
  {
    return _outpin;
  }

};


#endif //LEDONBTN_H