#ifndef State_h
#define State_h

#include "../Parts/include/Part.h"
#include <vector>

using namespace std;

class State
{
private:
	vector<Part*> List;

public:
	State(vector<Part*> list);
	vector<Part*> getState();
};

#endif // !State_h