// playground.ino
#include "../RPlib/test/TypeSizePrinter.h"
#include "../RPlib/util/Soundbank.h"

#define soundPin 9

TypeSizePrinter printer(true);

void setup()
{
	Serial.begin(9600);
	Soundbank::soundSuccess(soundPin);
}

void loop()
{
	printer.run(millis());
}