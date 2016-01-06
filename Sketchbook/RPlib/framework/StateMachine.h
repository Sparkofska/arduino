#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "Arduino.h"
#include "State.h"

class StateMachine 
{
private:
	State* _currentState;

public:
	StateMachine(State* startState)
	: _currentState(startState)
	{

	}

	changeState()
	{
		_currentState->exitAction();
		_currentState = newState;
		_currentState->entryAction();
	}
};


#endif //STATEMACHINE_H