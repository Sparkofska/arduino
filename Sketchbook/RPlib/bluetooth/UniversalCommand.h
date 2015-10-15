#ifndef UNIVERSALCOMMAND_H
#define UNIVERSALCOMMAND_H

#include <vector>
#include "Command.h"

class UniversalCommand : public Command
{
private:
	std::vector<byte> _fields;

protected:


public:
  UniversalCommand(byte tag) : Command(tag) { };

  byte* getFields(byte &length)
  {
    length = _fields.size();
    return &_fields[0];
  }

  void clearFields()
  {
    _fields.clear();
  }

  void addField(byte newField)
  {
    _fields.push_back(newField);
  }
};

#endif //UNIVERSALCOMMAND_H