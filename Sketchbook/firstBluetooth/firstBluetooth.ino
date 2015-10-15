// firstBluetooth.ino

#define redPin 6
#define greenPin 5
#define bluePin 4

bool _rState = true;
bool _gState = true;
bool _bState = true;

void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	doR();
	doG();
	doB();

	Serial.begin(9600);
}

void loop()
{
	char r;
	if(Serial.available())
	{
		r = Serial.read();

		switch (r)
		{
			case 'r':
				doR();
				break;
			case 'g':
				doG();
				break;
			case 'b':
				doB();
				break;
			default:
		      // do nothing
		      break;
		}
	}
}

void doR()
{
	_rState = !_rState;
	digitalWrite(redPin, _rState ? HIGH : LOW);
}
void doG()
{
	_gState = !_gState;
	digitalWrite(greenPin, _gState ? HIGH : LOW);
}
void doB()
{
	_bState = !_bState;
	digitalWrite(bluePin, _bState ? HIGH : LOW);
}