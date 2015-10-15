#ifndef HANDLE_H
#define HANDLE_H


#include <list>
#include "Arduino.h"

class Task;

class Handle
{
private:
	std::list<Task*> _ongoingTasks;

public:
  Handle() { };

  void run();

  inline void registerTask(Task *task);

  inline void unregisterTask(Task *task);

  void printOngoingTasks();
  
};

#endif //HANDLE_H