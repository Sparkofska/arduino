//Handle.cpp

#include "Handle.h"
#include "Task.h"


  void Handle::run()
  {
    for(std::list<Task*>::iterator it = _ongoingTasks.begin(); it !=_ongoingTasks.end(); it++)
    {
      (*it)->run(millis());
    }
  }

  inline void Handle::registerTask(Task *task)
  {
  	_ongoingTasks.push_back(task);
  }

  inline void Handle::unregisterTask(Task *task)
  {
  	_ongoingTasks.remove(task);
  }

  void Handle::printOngoingTasks()
  {
  	for(std::list<Task*>::iterator it = _ongoingTasks.begin(); it !=_ongoingTasks.end(); it++)
  	{
  		Serial.println((*it)->getId());
  	}
  }