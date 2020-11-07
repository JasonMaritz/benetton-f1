#ifndef Memento_h
#define Memento_h

#include "State.h"

class Memento
{
private:
	State* state;

public:
	vector<Parts*> getState();
	void setState(vector<Parts*> list);
};

#endif // !Memento_h