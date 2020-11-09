#include "Memento.h"

vector<Part*> Memento::getState()
{
	return state->getState();
}

void Memento::setState(vector<Part*> list)
{
	state = new State(list);
}
