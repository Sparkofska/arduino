// firstDistance.ino

#include "StandardCplusplus.h"
#include "system_configuration.h"
#include "unwind-cxx.h"
#include "utility.h"

#include "../RPlib/framework/Arrange.h"
#include "../RPlib/framework/Arrange.cpp"
#include "../RPlib/distance/DistancePrinter.h"
#include "../RPlib/distance/DistanceBlinker.h"
#include "../RPlib/distance/DistanceListener.h"
#include "../RPlib/continuals/Blinker.h"

#define ledPin 13
#define signalPin 11 	// IN
#define triggerPin 10 	// OUT
#define distLedPin 8

Blinker blinker(0, 500L, ledPin);

//DistancePrinter callable;
DistanceBlinker callable(distLedPin, 300);
DistanceListener listener(1, 333L, signalPin, triggerPin, &callable);

void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&listener);

	Serial.println("started");
}

void loop()
{
	Arrange::getInstance()->spin();
}

