#include "State.h"

State::State(vector<Part*> list)
{
	for (vector<Part*>::iterator it = list.begin(); it != list.end(); it++)
	{
		List.push_back((*it)->clone());
	}
}

vector<Part*> State::getState()
{
	return List;
}
