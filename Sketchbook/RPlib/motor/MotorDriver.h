#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "../framework/Continual.h"

class MotorDriver : public Continual
{

#define NUM_GRADATIONS 4

private:
  byte _A1Pin;
  byte _A2Pin;
  byte _enAPin; //needs to be PWM
  byte _B1Pin;
  byte _B2Pin;
  byte _enBPin; //needs to be PWM

  bool _turn;

  char _speedAindex; // char: because negative values are needed, too
  char _speedBindex;

  void driveA()
  {
    if(_speedAindex == 0)
    {
      analogWrite(_enAPin, 0);
      digitalWrite(_A1Pin, LOW);
      digitalWrite(_A2Pin, LOW);
    }
    else if(_speedBindex > 0) // forward
    {
      analogWrite(_enAPin, calcSpeed(_speedAindex));
      digitalWrite(_A1Pin, HIGH);
      digitalWrite(_A2Pin, LOW);
    }
    else //backward
    {
      analogWrite(_enAPin, calcSpeed(_speedAindex));
      digitalWrite(_A1Pin, LOW);
      digitalWrite(_A2Pin, HIGH);
    }
  }

  void driveB()
  {
    if(_speedBindex == 0)
    {
      analogWrite(_enBPin, 0);
      digitalWrite(_B1Pin, LOW);
      digitalWrite(_B2Pin, LOW);
    }
    else if(_speedBindex > 0) // forward
    {
      analogWrite(_enBPin, calcSpeed(_speedBindex));
      digitalWrite(_B1Pin, HIGH);
      digitalWrite(_B2Pin, LOW);
    }
    else //backward
    {
      analogWrite(_enBPin, calcSpeed(_speedBindex));
      digitalWrite(_B1Pin, LOW);
      digitalWrite(_B2Pin, HIGH);
    }
  }

  byte calcSpeed(char index)
  {
    Serial.print("calcSpeed called: i=");
    Serial.println((int) index);

    if(index < 0)
      index = -index;

    switch (index)
    {
      case 0:
        return 220;
       case 1:
        return 230;
       case 2:
        return 240;
       case 3:
        return 250;
       case 4:
        return 255;
      default:
        return 0;
    }
  }

protected:
  void work(long now)
  {
    if(_turn){
      driveA();
      driveB();
    }
    else{
      driveB();
      driveA();
    }

    _turn = !_turn;
  }

public:
  /**
  * 
  */
  MotorDriver(byte id, long pace, byte A1Pin, byte A2Pin, byte enAPin, byte B1Pin, byte B2Pin, byte enBPin)
    : Continual(id, pace)
    , _A1Pin(A1Pin), _A2Pin(A2Pin), _enAPin(enAPin)
    , _B1Pin(B1Pin), _B2Pin(B2Pin), _enBPin(enBPin),
    _speedAindex(0), _speedBindex(0)
    {
      pinMode(_A1Pin, OUTPUT);
      pinMode(_A2Pin, OUTPUT);
      pinMode(_enAPin, OUTPUT);
      pinMode(_B1Pin, OUTPUT);
      pinMode(_B2Pin, OUTPUT);
      pinMode(_enBPin, OUTPUT);

      digitalWrite(_A1Pin, LOW);
      digitalWrite(_A2Pin, LOW);
      digitalWrite(_enAPin, LOW);
      digitalWrite(_B1Pin, LOW);
      digitalWrite(_B2Pin, LOW);
      digitalWrite(_enBPin, LOW);
    };

    ~MotorDriver()
    {
    }

    void increaseASpeed()
    {
      if(_speedAindex < NUM_GRADATIONS)
        _speedAindex++;
    }

    void decreaseASpeed()
    {
      if(_speedAindex > -NUM_GRADATIONS)
        _speedAindex--;
    }

    void increaseBSpeed()
    {
      if(_speedBindex < NUM_GRADATIONS)
        _speedBindex++;
    }

    void decreaseBSpeed()
    {
      if(_speedBindex > -NUM_GRADATIONS)
        _speedBindex--;
    }
};


#endif //MOTORDRIVER_H