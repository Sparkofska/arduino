#ifndef ROBERTCOMMANDEXECUTOR_H
#define ROBERTCOMMANDEXECUTOR_H

#include "../RPlib/bluetooth/CommandExecutor.h"
#include "../RPlib/bluetooth/Command.h"
#include "../RPlib/motor/MotorDriver.h"

class RobertCommandExecutor : public CommandExecutor
{

private:
	byte _ledPin;
	bool _ledState;

  MotorDriver* _motordriver;

	void testCmdByLed()
	{
		_ledState = !_ledState;
		digitalWrite(_ledPin, _ledState);
	}

protected:

public:
  RobertCommandExecutor(byte ledPin, MotorDriver* motordriver):
  	CommandExecutor(),
  	_ledPin(ledPin),
  	_ledState(false),
    _motordriver(motordriver)
  { 
  	pinMode(_ledPin, OUTPUT);
  	digitalWrite(_ledPin, LOW);
  };

  void execute(Command& cmd)
  {
  	switch(cmd.getTag()) {
    	case 'g' :
    		testCmdByLed();
            break;

      case 'a' :
        _motordriver->increaseASpeed();
            break;
      case 's' :
        _motordriver->decreaseASpeed();
            break;
      case 'b' :
        _motordriver->increaseBSpeed();
            break;
      case 'n' :
        _motordriver->decreaseBSpeed();
            break;
            
    	default:
    		Serial.write("Cmd not specified");
	}
  }

};


#endif //ROBERTCOMMANDEXECUTOR_H