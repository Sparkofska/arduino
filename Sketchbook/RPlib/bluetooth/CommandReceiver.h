#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include "../framework/Continual.h"
#include "UniversalCommand.h"
#include "CommandExecutor.h"

class CommandReceiver : public Continual
{

private:
  CommandExecutor* _executor;

protected:
  void work(long now)
  {
    if(Serial.available())
    {
      //get command's tag
      UniversalCommand cmd(Serial.read());

      while(Serial.available())
      {
        //read all the data fields until CMD_END is reached
        byte x = Serial.read();
        if(x != Command::CMD_END)
        {
          //next field
          cmd.addField(x);
        }
        else
        {
          //command end
          _executor->execute(cmd);
          return;
        }
      }
      Serial.print("Cmd was dismissed due to invalid syntax");
    }
  }

public:
  CommandReceiver(byte id, long pace, CommandExecutor* executor)
    : Continual(id, pace), _executor(executor)
    {
      Serial.begin(9600);
    };

  ~CommandReceiver(){
    delete _executor;
  }



};


#endif //COMMANDRECEIVER_H