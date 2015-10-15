#ifndef DISTANCELISTENER_H
#define DISTANCELISTENER_H

#include "../framework/Continual.h"
#include "OnDistanceCallable.h"

#define V_SOUND 343 // Schallgeschwindigkeit in mm/ms Millimeter pro Millisekunde beo 20°C Raumtemperatur

class DistanceListener : public Continual
{

private:
  byte _signalpin;  //IN
  byte _triggerpin; //OUT
  OnDistanceCallable *_onDistance;

  inline void prepareForNextMeasure() {
    digitalWrite(_triggerpin, HIGH);
  }

  /** Schallgeschwindigkeit in mm/ms abhängig von Temperatur in °C*/
  inline int calcVSoundWithTemp(int temp) {
    return (3315 + 6*temp) / 10;
  }


protected:
  void work(long now)
  {
    digitalWrite(_triggerpin, LOW); // Messung triggern
    //Serial.println("triggered");

    unsigned long duration = pulseIn(_signalpin, HIGH);  // Signal lesen, timeout in microseconds

    //Serial.print("dur= ");
    //Serial.println(duration);

    if(duration == 0) // pulseIn hat innerhalb timeout kein Signal bekommen
    {
      Serial.println("timeout before distance");
    }

    else if(duration < 2000 * 1000) // Messung erfolgreich
    {
      unsigned long distmm = (duration * V_SOUND)/ (2*1000);
      _onDistance->onDistance(distmm);
    }
    else
      Serial.println(" >200 000");
    // else Messung erfolglos : no op

    //vorbereiten für nächste Messung
    prepareForNextMeasure();
  }

public:

  DistanceListener(byte id, long pace, byte inpin, byte outpin, OnDistanceCallable* onDistanceClbl)
  : Continual(id, pace),
  _onDistance(onDistanceClbl)
    {
      setInpin(inpin);
      setOutpin(outpin);
      prepareForNextMeasure();
    }

  inline void setInpin(byte inpin)
  {
    _signalpin = inpin;
    pinMode(_signalpin, INPUT);
  }

  inline void setOutpin(byte outpin)
  {
    _triggerpin = outpin;
    pinMode(_triggerpin, OUTPUT);
  }

};

#endif //DISTANCELISTENER_H