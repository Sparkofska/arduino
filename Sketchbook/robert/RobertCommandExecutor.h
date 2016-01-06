#ifndef ROBERTCOMMANDEXECUTOR_H
#define ROBERTCOMMANDEXECUTOR_H

#include "../RPlib/bluetooth/CommandExecutor.h"
#include "../RPlib/bluetooth/Command.h"
/**
* virtual class. Should be overridden for Executing specialized commands.
*/
class RobertCommandExecutor : public CommandExecutor
{

private:
	byte _ledPin;
	bool _ledState;

	void testCmdByLed()
	{
		_ledState = !_ledState;
		digitalWrite(_ledPin, _ledState);
	}

protected:

public:
  RobertCommandExecutor(byte ledPin):
  	CommandExecutor(),
  	_ledPin(ledPin),
  	_ledState(false)
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
    	default:
    		Serial.write("Cmd not specified");
	}
  }

};


#endif //ROBERTCOMMANDEXECUTOR_H