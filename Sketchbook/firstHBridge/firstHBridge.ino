// firstHBridge.ino

#define ENA 5
#define IN1 3
#define IN2 2

byte i;

void setup()
{
	Serial.begin(9600);

	pinMode(ENA, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	i=0;
	Serial.println("start");
}

void loop()
{
	digitalWrite(ENA, HIGH);

	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	delay(1000);

	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);

	delay(1000);

}

