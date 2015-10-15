#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "../framework/Continual.h"
#include "SpeedCalculator.h"

class MotorDriver : public Continual
{

private:
  byte _A1Pin;
  byte _A2Pin;
  byte _enAPin; //needs to be PWM
  byte _B1Pin;
  byte _B2Pin;
  byte _enBPin; //needs to be PWM

  SpeedCalculator *_speedcalc;

  const static int TRESHHOLD = 5; // below this Value motors wont drive

  inline int absClamp255(int x)
  {
    if(x < 0)   x = -x;
    if(x > 255) x = 255;
    return x;
  }

  inline void driveA(int speed)
  {
    if(speed > 0) // forward
    {
      analogWrite(_enAPin, absClamp255(speed));
      digitalWrite(_A1Pin, HIGH);
      digitalWrite(_A2Pin, LOW);
    }
    else //backward
    {
      analogWrite(_enAPin, absClamp255(speed));
      digitalWrite(_A1Pin, LOW);
      digitalWrite(_A2Pin, HIGH);
    }
  }

  inline void stopA()
  {
    analogWrite(_enAPin, 0);
  }

  inline void stopB()
  {
    analogWrite(_enBPin, 0);
  }

  inline void driveB(int speed)
  {
    if(speed > 0) // forward
    {
      analogWrite(_enBPin, absClamp255(speed));
      digitalWrite(_B1Pin, HIGH);
      digitalWrite(_B2Pin, LOW);
    }
    else //backward
    {
      analogWrite(_enBPin, absClamp255(speed));
      digitalWrite(_B1Pin, LOW);
      digitalWrite(_B2Pin, HIGH);
    }
  }

protected:
  void work(long now)
  {
    int a = _speedcalc->getASpeed();
    int b = _speedcalc->getBSpeed();

    if(a < TRESHHOLD && a > -TRESHHOLD)
      stopA();
    else
      driveA(a);

    if(b < TRESHHOLD && b > -TRESHHOLD)
      stopB();
    else
      driveB(b);
  }

public:
  /**
  * 
  */
  MotorDriver(byte id, long pace, SpeedCalculator* speedcalc, byte A1Pin, byte A2Pin, byte enAPin, byte B1Pin, byte B2Pin, byte enBPin)
    : Continual(id, pace)
    , _A1Pin(A1Pin), _A2Pin(A2Pin), _enAPin(enAPin)
    , _B1Pin(B1Pin), _B2Pin(B2Pin), _enBPin(enBPin)
    , _speedcalc(speedcalc)
    {
      pinMode(_A1Pin, OUTPUT);
      pinMode(_A2Pin, OUTPUT);
      pinMode(_enAPin, OUTPUT);
      pinMode(_B1Pin, OUTPUT);
      pinMode(_B2Pin, OUTPUT);
      pinMode(_enBPin, OUTPUT);
    };

    ~MotorDriver()
    {
      delete _speedcalc;
    }


  void deactivate()
  {
    Continual::deactivate();
  }

};


#endif //MOTORDRIVER_H