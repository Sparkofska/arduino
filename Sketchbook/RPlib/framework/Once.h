#ifndef ONCE_H
#define ONCE_H

#include "Arduino.h"
#include "Task.h"

class Once : public Task
{

private:
  bool _active;

protected:
  virtual void work(long now) = 0;

public:
  Once(byte id, bool active)
    :Task(id), _active(active)
    {
    };
	
  Once(byte id)
    :Task(id), _active(true)
    {
    };

  void run(long currentTime)
  {
    if(! getActive())
      return;
    work(currentTime);
    deactivate();
  }

  inline virtual void activate()
  {
    _active = true;
  }

  inline virtual void deactivate()
  {
    _active = false;
  }

  inline virtual bool getActive()
  {
    return _active;
  }
};


#endif //ONCE_H