#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include "Command.h"
/**
* virtual class. Should be overridden for Executing specialized commands.
*/
class CommandExecutor
{

private:

protected:

public:
  CommandExecutor()
  { };

  virtual void execute(Command& cmd) =0;

};


#endif //COMMANDEXECUTOR_H