#ifndef SOUNDSUCCESSPLAYER_H
#define SOUNDSUCCESSPLAlude "Once(true)ce.h"

#include "../framework/Once.h"
#include "../util/Soundbank.h"

class SoundSuccessPlayer : public Once
{

private:
  byte _outpin;

protected:
  void work(long now)
  {
    Soundbank::soundSuccess(_outpin);
  }

public:
  /**
  * 
  */
  SoundSuccessPlayer(byte id, byte outpin)
  :Once(id)
    {
      setOutpin(outpin);
    };

  inline void setOutpin(byte outpin)
  {
    _outpin = outpin;
    pinMode(_outpin, OUTPUT);
  }

  inline byte getOutpin()
  {
    return _outpin;
  }

};


#endif //SOUNDSUCCESSPLAYER_H