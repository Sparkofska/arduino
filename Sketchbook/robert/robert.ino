// robert.ino

#include "StandardCplusplus.h"
#include "system_configuration.h"
#include "unwind-cxx.h"
#include "utility.h"

#include "../RPlib/util/Soundbank.h"

#include "../RPlib/framework/Continual.h"
#include "../RPlib/framework/Arrange.h"
#include "../RPlib/framework/Arrange.cpp"

#include "../RPlib/continuals/Blinker.h"

#include "../RPlib/bluetooth/CommandReceiver.h"
//#include "../RPlib/bluetooth/Command.h"
#include "../RPlib/bluetooth/CommandExecutor.h"
#include "RobertCommandExecutor.h"

#include "../RPlib/distance/DistanceListener.h"
#include "../RPlib/distance/DistancePrinter.h"
#include "DistanceConsumer.h"

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
#define ledPin 4

#define distanceTriggerPin 3		//PWM
#define distanceEchoPin 2

#define xxx 1 		//TX->
#define xxx 0		//RX<-

Blinker blinker(1, 500L, blinkPin);

RobertCommandExecutor cmdExe(ledPin);
CommandReceiver receiver(2, 20L, &cmdExe);

DistanceConsumer consumer(soundPin, 200L);
//DistancePrinter p;
DistanceListener distanceListener(3, 333L, distanceEchoPin, distanceTriggerPin, &consumer);

//FrequenzLogger frequenzLogger(4, 1000L);

void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&distanceListener);
	Arrange::getInstance()->registerTask(&receiver);

	//Arrange::getInstance()->registerTask(&frequenzLogger);

	Serial.write("setup finished");

	pinMode(soundPin, OUTPUT);
	Soundbank::soundStarted(soundPin);
}

void loop()
{
	Arrange::getInstance()->spin();
}
