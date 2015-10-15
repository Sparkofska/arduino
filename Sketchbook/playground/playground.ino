// playground.ino

#include "StandardCplusplus.h"
#include "system_configuration.h"
#include "unwind-cxx.h"
#include "utility.h"

#include "../RPlib/util/Soundbank.h"
#include "../RPlib/framework/Continual.h"
#include "../RPlib/framework/Arrange.h"
#include "../RPlib/framework/Arrange.cpp"
#include "../RPlib/button/ButtonListener.h"
#include "../RPlib/button/OnPressCallable.h"
#include "../RPlib/continuals/Blinker.h"
#include "../RPlib/continuals/LedOnBtn.h"
#include "../RPlib/onces/SoundSuccessPlayer.h"
#include "../RPlib/util/FrequenzLogger.h"

#define buttonPin 5
#define ledbtn 7
#define ledBPin 9
#define soundPin 11
#define ledPin 13


Blinker blinker(1, 1000L, ledPin);
Blinker blinker2(2, 333L, ledBPin);
FrequenzLogger logger(3, 1000L);
LedOnBtn onPress(ledbtn);
ButtonListener btnListener(4, 100L, buttonPin, &onPress);

void setup()
{
	Serial.begin(9600);

	Arrange::getInstance()->registerTask(&blinker);
	Arrange::getInstance()->registerTask(&blinker2);
	Arrange::getInstance()->registerTask(&logger);
	Arrange::getInstance()->registerTask(&btnListener);

	Soundbank::soundSuccess(soundPin);

	Serial.println("s");
}

void loop()
{
	//Serial.println("l");
	Arrange::getInstance()->spin();
	//delay(2000);
	//Soundbank::soundBeep(soundPin);
}
