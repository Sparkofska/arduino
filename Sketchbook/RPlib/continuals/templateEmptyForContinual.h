#ifndef TEMPLATE
#define TEMPLATE

#include "../framework/Continual.h"

class template : public Continual
{

private:
  //define member fields here
  byte _outpin;

protected:
  void work(long now)
  {
    //write loop code here
  }

public:
  //implement constructor
  template(byte id, long pace, byte outpin)
    : Continual(id, pace)
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

};


#endif //TEMPLATE