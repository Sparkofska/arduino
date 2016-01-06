// emptyAndClean.ino

#define ledPin 13

void setup() {
	pinMode(ledPin, OUTPUT);

	//Serial.begin(9600);
	//Serial.println("started");

}

void loop() {
	digitalWrite(ledPin, HIGH);
	delay(500);
	digitalWrite(ledPin, LOW);
	delay(500);

}

