#include "Memento.h"

vector<Parts*> Memento::getState()
{
	return state->getState();
}

void Memento::setState(vector<Parts*> list)
{
	state = new State(list);
}
