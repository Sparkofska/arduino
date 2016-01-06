#ifndef STATE_H
#define STATE_H

#include "Arduino.h"

class State 
{
public:

  inline virtual void entryAction() =0;

  inline virtual void exitAction() =0;

  inline virtual void update() =0;
  
};


#endif //STATE_H