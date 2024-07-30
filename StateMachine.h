#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>

#include "State.h"


typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void addState(StateRef newState, bool isReplacing = true);
	void removeState();

	void processStateEvents();

	StateRef& getActiveState();

private:
	std::stack<StateRef> _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;
};

#endif

