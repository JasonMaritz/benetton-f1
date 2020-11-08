#ifndef Memento_h
#define Memento_h

#include "State.h"

class State;

class Memento
{
private:
	State* state;

public:
	vector<Part*> getState();
	void setState(vector<Part*> list);
};

#endif // !Memento_h