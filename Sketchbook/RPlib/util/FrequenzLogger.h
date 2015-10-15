#ifndef FREQUENZLOGGER_H
#define FREQUENZLOGGER_H

#include "../framework/Continual.h"

class FrequenzLogger : public Continual
{

private:
  long _lastPrint;
  long _printPace;

  unsigned int _loopCounter;

protected:
  void work(long now)
  {
    _loopCounter++;

    if(now - _lastPrint > _printPace)
    {
      _lastPrint = now;

      float frequenz = 1000.f * ( (float)_loopCounter / (float)_printPace );

      Serial.print(frequenz);
      Serial.println(" Hz");

      _loopCounter =0;
    }

  }

public:
  FrequenzLogger(byte id, long printPace)
    : Continual(id, 0),
      _printPace(printPace),
      _loopCounter(0)
    {
      Serial.begin(9600);
    };

};


#endif //FREQUENZLOGGER_H