#include "Arrange.h"
#include "Task.h"

void Arrange::spin()
{
	for(std::list<Task*>::iterator it = _ongoingTasks.begin(); it !=_ongoingTasks.end(); it++)
    {
      		(*it)->run(millis());
    }
}

inline void Arrange::registerTask(Task *task)
{
	_ongoingTasks.push_back(task);
}

inline void Arrange::unregisterTask(Task *task)
{
	_ongoingTasks.remove(task);
}

void Arrange::printOngoingTasks()
{
	Serial.println("ongoing:");
	for(std::list<Task*>::iterator it = _ongoingTasks.begin(); it !=_ongoingTasks.end(); it++)
	{
		Serial.println((*it)->getId());
	}
	Serial.print("len ");
	Serial.println(_ongoingTasks.size());
}