// robert.ino

#include "StandardCplusplus.h"
#include "system_configuration.h"
#include "unwind-cxx.h"
#include "utility.h"

#include "../RPlib/util/Soundbank.h"

#include "Robert.h"

void setup()
{
	pinMode(soundPin, OUTPUT);
	Soundbank::soundStarting(soundPin);

	Serial.begin(9600);

	Robert::get()->setup();

	Serial.write("setup finished");
	Soundbank::soundStarted(soundPin);
}

void loop()
{
	Arrange::getInstance()->spin();
}

