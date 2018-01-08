#ifndef CONTINUAL_H
#define CONTINUAL_H

#include "Arduino.h"
#include "Task.h"

class Continual : public Task
{

private:
  bool _active;

protected:
  unsigned long _pace; //time between executions
  unsigned long _lastExec;
  virtual void work(long now) = 0;

public:
  /**
  * pace gibt an nach wie vielen millis der Task wieder anspringen soll. 0 = immer
  */
  Continual(byte id, unsigned long pace)
    :Task(id), _pace(pace), _lastExec(0), _active(true)
    {
      
    };


  void run(unsigned long currentTime)
  {
    if(!_active)
      return;
    if(currentTime - _lastExec < _pace)
      return;

    work(currentTime);
    _lastExec = currentTime;
  }

  inline void setPace(unsigned long pace) { _pace = pace; }

  inline virtual void activate() { _active = true; }

  inline virtual void deactivate() { _active = false; }

  inline virtual bool getActive() { return _active; }
};


#endif //CONTINUAL_H
