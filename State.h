#ifndef State_h
#define State_h

#include "Parts.h"
#include <vector>

using namespace std;

class State
{
private:
	vector<Parts*> List;

public:
	State(vector<Parts*> list);
	vector<Parts*> getState();
};

#endif // !State_h