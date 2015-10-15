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
#include "../RPlib/distance/DistanceListener.h"
#include "DistanceConsumer.h"

//#include "../RPlib/Distance/DistancePrinter.h"
//#include "../RPlib/util/FrequenzLogger.h"

#define ledPin 13

#define motorA1pin 12
#define motorA2pin 11	//PWM
#define motorENApin 10 	//PWM
#define motorENBpin 9 	//PWM
#define mototrB1pin 8
#define motorB2pin 7
#define soundPin 6		//PWM
#define xxx 5		//PWM
#define xxx 4
#define distanceTriggerPin 3		//PWM
#define distanceSignalPin 2
#define xxx 1 		//TX->
#define xxx 0		//RX<-

Blinker blinker(1, 500L, ledPin);

DistanceConsumer consumer(soundPin, 200L);
//DistancePrinter p;
DistanceListener distanceListener(2, 333L, distanceSignalPin, distanceTriggerPin, &consumer);
//FrequenzLogger frequenzLogger(3, 1000L);

void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&distanceListener);
	//Arrange::getInstance()->registerTask(&frequenzLogger);

	pinMode(soundPin, OUTPUT);
	Soundbank::soundStarted(soundPin);
}

void loop()
{
	Arrange::getInstance()->spin();
}