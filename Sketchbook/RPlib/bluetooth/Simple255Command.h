#ifndef SIMPLE255COMMAND_H
#define SIMPLE255COMMAND_H

#include "Command.h"

class Simple255Command : Command
{
private:
	unsigned byte _field;

protected:
	unsigned byte[] getFields(byte &length)
  {
    length = 1;
    unsigned byte a[1] = { _field };
    return a;
  }

public:
  Simple255Command(byte tag, unsigned byte field) :
    Command(tag),
    _field(field) { };

  int getField(){return _field;}
  void setField(unsigned byte field){_field = field;}
};

#endif //SIMPLE255COMMAND_H