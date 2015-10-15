#ifndef BLINKER_H
#define BLINKER_H

#include "../framework/Continual.h"

class Blinker : public Continual
{

private:
  byte _outpin;
  bool _state;

protected:
  void work(long now)
  {
    _state = !_state;
    digitalWrite(_outpin, _state ? HIGH : LOW);
  }

public:
  /**
  * 
  */
  Blinker(byte id, long pace, byte outpin)
    : Continual(id, pace),
    _state(true)
    {
      setOutpin(outpin);
    };

  inline void setOutpin(byte outpin)
  {
    _outpin = outpin;
    pinMode(_outpin, OUTPUT);
  }

  inline byte getOutpin()
  {
    return _outpin;
  }

  void deactivate()
  {
    Continual::deactivate();
    _state = false;
    digitalWrite(_outpin, LOW);
  }

};


#endif //BLINKER_H