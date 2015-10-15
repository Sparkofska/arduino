#ifndef ONPDISTANCECALLABLE_H
#define ONPDISTANCECALLABLE_H

class OnDistanceCallable
{
private:
  
public:
  OnDistanceCallable()
  { };

  //distance in mm, 1m = 1000mm
  virtual void onDistance(unsigned long distance) = 0;

};
#endif //ONPDISTANCECALLABLE_H