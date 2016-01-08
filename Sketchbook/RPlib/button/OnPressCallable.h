#ifndef ONPRESSCALLABLE_H
#define ONPRESSCALLABLE_H

class OnPressCallable
{
private:
  
public:
  OnPressCallable()
  { };

  virtual void onPress() = 0;
  virtual void onRelease() = 0;

};
#endif //ONPRESSCALLABLE_H
