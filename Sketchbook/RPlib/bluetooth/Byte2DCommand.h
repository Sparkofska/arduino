#ifndef BYTE2DCOMMAND_H
#define BYTE2DCOMMAND_H

#include "Command.h"

class Byte2DCommand : Command
{
private:
	byte _a;
	byte _b;

protected:
	unsigned byte[] getFields(byte &length)
  {
    length = 2;
    unsigned byte a[2] = { _a, _b };
    return a;
  }

public:
  Byte2DCommand(byte tag, byte a, byte b)
   : Command(tag)
   , _a(a), _b(b)
    { };
};

#endif //BYTE2DCOMMAND_H