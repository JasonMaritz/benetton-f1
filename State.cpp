#include "State.h"

State::State(vector<Parts*> list)
{
	for (vector<Parts*>::iterator it = list.begin; it != list.end; it++)
	{
		List.push_back((*it)->clone());
	}
}

vector<Parts*> State::getState()
{
	return List;
}
