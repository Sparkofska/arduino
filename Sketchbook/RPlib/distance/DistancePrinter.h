#ifndef DISTANCEPRINTER_H
#define DISTANCEPRINTER_H

#include "OnDistanceCallable.h"

class DistancePrinter : public OnDistanceCallable
{
private:
  
public:
  DistancePrinter()
  {
  	Serial.begin(9600);
  };

  //distance in mm, 1m = 1000mm
  virtual void onDistance(unsigned long distance) 
  {
  	int mm = distance % 10;
  	int cm = distance / 10;
  	Serial.print(cm);
  	Serial.print(",");
  	Serial.print(mm);
  	Serial.println("cm");
  }

};
#endif //DISTANCEPRINTER_H