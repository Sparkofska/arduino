#ifndef TESTSPEEDCALCULATOR_H
#define TESTSPEEDCALCULATOR_H

#include "../framework/Continual.h"
#include "SpeedCalculator.h"

class TestSpeedCalculator : public SpeedCalculator, public Continual
{
private:
	bool _motorA;
	bool _motorB;
	bool _backwardA;
	bool _stopA;
	bool _backwardB;
	bool _stopB;
  
public:
  TestSpeedCalculator(byte id, long pace)
  : Continual(id, pace)
  { 
  	Serial.begin(9600);
  	_motorA = false;
  	_motorB = false;
  	_stopA = true;
  	_backwardA = false;
  	_stopB = true;
  	_backwardB = false;
  };

  virtual void work(long now)
  {
  	if(Serial.available())
  	{
  		char r = Serial.read();
  		switch (r)
  		{
  			case 'a' :
  				_motorA = true;
  				_motorB = false;
  				break;
  			case 'b' :
  				_motorB = true;
  				_motorA = false;
  				break;
  			case 's' :
  				if(_motorA)
  					_stopA = !_stopA;
  				else if(_motorB)
  					_stopB = !_stopB;
  				break;
  			case 'f' :
  				if(_motorA)
  					_backwardA = false;
  				else if(_motorB)
  					_backwardB = false;
  				break;
  			case 'r' :
  				if(_motorA)
  					_backwardA = true;
  				else if(_motorB)
  					_backwardB = true;
  				break;
  			default:
  			break;
  		}
  	}
  }
  
  int getASpeed()
  {
  	if(_stopA)
  		return 0;
  	return _backwardA ? -255 : 255;
  }

  int getBSpeed()
  {
  	if(_stopB)
  		return 0;
  	return _backwardB ? -255 : 255;
  }

};
#endif //TESTSPEEDCALCULATOR_H