#ifndef CMDEXEPRINTER_H
#define CMDEXEPRINTER_H

#include "CommandExecutor.h"
#include "Command.h"

class CmdExePrinter : public CommandExecutor
{

private:

protected:

public:
  CmdExePrinter()
    {
    	Serial.begin(9600);
    }

  virtual void execute(Command& cmd)
  {
  	Serial.print("cmd: ");
  	Serial.print(cmd.getTag());
  	
  	byte l;
  	byte* f = cmd.getBytes(l);

  	Serial.print("[l=");
  	Serial.print(l);
  	Serial.print("]");

  	for(int i=0; i<l; i++)
  		Serial.print(f[i]);
  	Serial.println(Command::CMD_END);
  }

};


#endif //CMDEXEPRINTER_H