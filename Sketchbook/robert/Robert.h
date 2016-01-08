#ifndef ROBERT_H
#define ROBERT_H

#include "Arduino.h"

#include "../RPlib/framework/Continual.h"
#include "../RPlib/framework/Arrange.h"
#include "../RPlib/framework/Arrange.cpp"

#include "../RPlib/continuals/Blinker.h"

#include "../RPlib/bluetooth/CommandReceiver.h"
//#include "../RPlib/bluetooth/Command.h"
#include "../RPlib/bluetooth/CommandExecutor.h"

#include "../RPlib/distance/DistanceListener.h"
#include "../RPlib/distance/DistancePrinter.h"
#include "RobertDistanceCallable.h"

#include "../RPlib/motor/MotorDriver.h"

//#include "../RPlib/Distance/DistancePrinter.h"
//#include "../RPlib/util/FrequenzLogger.h"

#define blinkPin 13

#define motorA1pin 12
#define motorA2pin 11	//PWM
#define motorENApin 10 	//PWM
#define motorENBpin 9 	//PWM
#define motorB1pin 8
#define motorB2pin 7

#define soundPin 6		//PWM

#define xxx 5		//PWM
#define testLedPin 4

#define distanceTriggerPin 3		//PWM
#define distanceEchoPin 2

#define xxx 1 		//TX->
#define xxx 0		//RX<-

#define xxx A0
#define xxx A1 	//light Sensor?
#define xxx A2 	//light?
#define xxx A3
#define xxx A4
#define xxx A5

/*
Verwendung
==========
Robert::get()->xyz();
*/

class Robert : public CommandExecutor
{
private:

	Blinker _blinker;

	RobertDistanceCallable _consumer;
	//DistancePrinter _p;
	DistanceListener _distanceListener;

	MotorDriver _motordriver;

	CommandReceiver _receiver;

	//FrequenzLogger _frequenzLogger;

	bool _testLedState;

	Robert ()
		: _blinker(Blinker(1, 500L, blinkPin))

		, _consumer(RobertDistanceCallable(soundPin, 200L))
		, _distanceListener(DistanceListener(2, 333L, distanceEchoPin, distanceTriggerPin, &_consumer))

		, _motordriver(MotorDriver(3, 100L, motorA1pin, motorA2pin, motorENApin, motorB1pin, motorB2pin, motorENBpin))

		, _receiver(CommandReceiver(4, 20L, this))
		  //, frequenzLogger(FrequenzLogger(5, 1000L))

		, _testLedState(false)
	{
		pinMode(testLedPin, OUTPUT);
		digitalWrite(testLedPin, LOW);
	}

public:
	void setup()
	{
		Arrange::getInstance()->registerTask(&_blinker);
		//Arrange::getInstance()->registerTask(&distanceListener);
		Arrange::getInstance()->registerTask(&_receiver);

		Arrange::getInstance()->registerTask(&_motordriver);

		//Arrange::getInstance()->registerTask(&frequenzLogger);


		Serial.println(F("Robert was set up"));
	}

	void testCmdReceivingByLed()
	{
		_testLedState = !_testLedState;
		digitalWrite(testLedPin, _testLedState);
	}

	void execute(Command& cmd)
	{
		switch (cmd.getTag()) {
		case 'g' :
			testCmdReceivingByLed();
			break;

		case 'a' :
			_motordriver.increaseASpeed();
			break;
		case 's' :
			_motordriver.decreaseASpeed();
			break;
		case 'b' :
			_motordriver.increaseBSpeed();
			break;
		case 'n' :
			_motordriver.decreaseBSpeed();
			break;

		default:
			Serial.write("Cmd not specified");
		}
	}

//----------------------------------------------------------------------------------------------
//--Singeton - Stuff ---------------------------------------------------------------------------

	static Robert* get()
	{
		// keine Speicherbereinigung. Aber Robert soll/kann über gesamten Zeitraum bestehen bleiben
		if (!_instance)
			_instance = new Robert;
		return _instance;
	}

private:
	static Robert* _instance;

	~Robert () { }

	Robert ( const Robert& ); // verhindert, dass eine weitere Instanz via Kopie-Konstruktor erstellt werden kann



};

Robert* Robert::_instance = 0; // statische Elemente einer Klasse müssen initialisiert werden.

#endif //ROBERT_H