#ifndef CHARCOMMAND_H
#define CHARCOMMAND_H

#include "Command.h"

class CharCommand : Command
{
private:

protected:
	unsigned byte[] getFields(byte &length)
  {
    length = 0;
    unsigned byte a[0] = { };
    return a;
  }

public:
  CharCommand(byte tag, unsigned byte field) :
    Command(tag) { };
};

#endif //CHARCOMMAND_H