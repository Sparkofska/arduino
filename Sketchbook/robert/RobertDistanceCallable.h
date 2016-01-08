#ifndef ROBERTDISTANCECALLABLE_H
#define ROBERTDISTANCECALLABLE_H

#include "../RPlib/Distance/OnDistanceCallable.h"

class RobertDistanceCallable : public OnDistanceCallable
{
private:
  byte _soundPin;
  unsigned long _dist;
  
public:
  RobertDistanceCallable(byte outpin, unsigned long distance)
    : _soundPin(outpin), _dist(distance)
  {
  	pinMode(outpin, OUTPUT);
  };

  //distance in mm, 1m = 1000mm
  virtual void onDistance(unsigned long distance) 
  {
    if(distance < _dist)
      Soundbank::soundBeep(_soundPin);
  }

};
#endif //ROBERTDISTANCECALLABLE_H