#ifndef BTCMDEXESPEEDCALC_H
#define BTCMDEXESPEEDCALC_H

#include "../RPlib/framework/Continual.h"
#include "../RPlib/motor/SpeedCalculator.h"
#include "../RPlib/bluetooth/CommandExecutor.h"

class BtCmdExeSpeedCalc : public SpeedCalculator, public CommandExecutor
{
private:
  int _curASpeed;
  int _curBSpeed;

  inline int mapByteToMid0(byte b)
  {
    return (int)b - 127;
  }
  
public:
  BtCmdExeSpeedCalc()
  : _curASpeed(0), _curBSpeed(0)
  { 

  };

  void execute(Command& cmd)
  {
    if(cmd.getTag() == 'g')  // GO-Befehl
    {
      byte length =0;
      byte *ar = cmd.getBytes(length);

      if(length != 2)
        return;

      _curASpeed = mapByteToMid0( ar[0] );
      _curBSpeed = mapByteToMid0( ar[1] );
    }
  }

  int getASpeed()
  {
    return _curASpeed;
  }

  int getBSpeed()
  {
    return _curBSpeed;
  }

};
#endif //BTCMDEXESPEEDCALC_H