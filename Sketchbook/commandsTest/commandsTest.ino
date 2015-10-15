// commandsTest.ino

#include "StandardCplusplus.h"
#include "system_configuration.h"
#include "unwind-cxx.h"
#include "utility.h"

#include "../RPlib/framework/Arrange.h"
#include "../RPlib/framework/Arrange.cpp"
#include "../RPlib/continuals/Blinker.h"
#include "../RPlib/bluetooth/CommandReceiver.h"
#include "../RPlib/bluetooth/CmdExePrinter.h"

#define ledPin 13

CmdExePrinter printer;

Blinker blinker(1, 500, ledPin);
CommandReceiver cmdReceiver(2, 40L, &printer);


void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&cmdReceiver);

	Serial.println("started");
}

void loop()
{
	Arrange::getInstance()->spin();
}