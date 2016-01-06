// firstBluetooth.ino

#include "../RPlib/util/Soundbank.h"

#define ledPin 13

#define motorA1pin 12
#define motorA2pin 11	//PWM
#define motorENApin 10 	//PWM
#define motorENBpin 9 	//PWM
#define motorB1pin 8
#define motorB2pin 7

#define soundPin 6

bool _ledState = false;
bool _motorAState = false;
bool _motorBState = false;

void setup()
{
  pinMode(ledPin, OUTPUT);

  pinMode(motorA1pin, OUTPUT);
  pinMode(motorA2pin, OUTPUT);
  pinMode(motorENApin, OUTPUT);
  pinMode(motorB1pin, OUTPUT);
  pinMode(motorB2pin, OUTPUT);
  pinMode(motorENBpin, OUTPUT);

  digitalWrite(motorA1pin, LOW);
  digitalWrite(motorA2pin, LOW);
  analogWrite(motorENApin, 0);
  digitalWrite(motorB1pin, LOW);
  digitalWrite(motorB2pin, LOW);
  analogWrite(motorENBpin, 0);

  pinMode(soundPin, OUTPUT);
  Soundbank::soundStarted(soundPin);

  Serial.begin(9600);
  Serial.write("setup finished");
}

void loop()
{
  char r;
  if (Serial.available())
  {
    r = Serial.read();

    switch (r)
    {
      case 'g':
      doTestLed();
      break;
      case 'a':
      if (_motorAState)
      stopMotor('a');
      else
      startMotor('a');
      break;
      case 'b':
      if (_motorBState)
      stopMotor('b');
      else
      startMotor('b');
      break;
      default:
        // do nothing
        break;
      }
    }
  }

  void startMotor(char whichMotor)
  {
    byte en;
    byte a1;
    byte a2;

    if (whichMotor == 'a')
    {
      en = motorENApin;
      a1 = motorA1pin;
      a2 = motorA2pin;

      _motorAState = true;
    }
    else if (whichMotor == 'b')
    {
      en = motorENBpin;
      a1 = motorB1pin;
      a2 = motorB2pin;

      _motorBState = true;
    }
    else
    return;

    Serial.write("starting");
    delay(500);

  //start the Motor slowly

  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);

  //for (int i = 100; i < 255; i = i + 2)
  //{
  //  analogWrite(en, i);
  //  delay(50);
  //}
  analogWrite(en, 255);
  Serial.write("started");
}

void stopMotor(char whichMotor)
{
  byte en;
  byte a1;
  byte a2;

  if (whichMotor == 'a')
  {
    en = motorENApin;
    a1 = motorA1pin;
    a2 = motorA2pin;

    _motorAState = false;
  }
  else if (whichMotor == 'b')
  {
    en = motorENBpin;
    a1 = motorB1pin;
    a2 = motorB2pin;

    _motorBState = false;
  }
  else
  return;

  Serial.write("stopping");

  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  analogWrite(en, 0);

  Serial.write("stopped");
}

void doTestLed()
{
  Serial.write("led");
  _ledState = !_ledState;
  digitalWrite(ledPin, _ledState ? HIGH : LOW);
}
