// playground.ino

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

#include "../RPlib/motor/MotorDriver.h"
#include "../RPlib/motor/TestSpeedCalculator.h"
#include "BtCmdExeSpeedCalc.h"

#define ledPin 13

#define a1pin 12
#define a2pin 11	//PWM
#define enapin 10 	//PWM
#define enbpin 9 	//PWM
#define b1pin 8
#define b2pin 7

#define soundPin 3 	//PWM

// txPin 1
// rxPin 0


Blinker blinker(1, 1000L, ledPin);

BtCmdExeSpeedCalc calc;
CommandReceiver receiver(2, 50L, &calc);
MotorDriver driver(3, 100L, &calc, a1pin, a2pin, enapin, b1pin, b2pin, enbpin);

void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&receiver);
	Arrange::getInstance()->registerTask(&driver);

	pinMode(soundPin, OUTPUT);
	Soundbank::soundStarted(soundPin);
}

void loop()
{
	//Serial.println("l");
	Arrange::getInstance()->spin();
}
