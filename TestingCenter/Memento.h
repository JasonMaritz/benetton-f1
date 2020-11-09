#ifndef Memento_h
#define Memento_h

#include "State.h"

class State;

class Memento
{
private:
	State* state;

public:
	/// @brief This returns the vector<Part*> that was stored in state
	/// @return vector<Part*>
	vector<Part*> getState();

	/// @brief This sets the state with a vector<Part*>
	/// @param list is the vector<Part*> parameter
	void setState(vector<Part*> list);
};

#endif // !Memento_h