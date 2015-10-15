#ifndef DISTANCEBLINKER_H
#define DISTANCEBLINKER_H

#include "OnDistanceCallable.h"

class DistanceBlinker : public OnDistanceCallable
{
private:
  byte _ledPin;
  unsigned long _dist;
  
public:
  DistanceBlinker(byte outpin, unsigned long distance)
    : _ledPin(outpin), _dist(distance)
  {
  	pinMode(outpin, OUTPUT);
  };

  //distance in mm, 1m = 1000mm
  virtual void onDistance(unsigned long distance) 
  {
  	digitalWrite(_ledPin, distance < _dist ? HIGH : LOW);
  }

};
#endif //DISTANCEBLINKER_H