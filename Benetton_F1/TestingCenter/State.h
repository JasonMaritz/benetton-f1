#ifndef State_h
#define State_h

#include "../Parts/include/Part.h"
#include <vector>

class Part;

using namespace std;

class State
{
private:
	vector<Part*> List;

public:
	/// @brief This is the constructor for the state
	/// @param list is the vector<Part*> that will be assigned to a memeber
	State(vector<Part*> list);

	/// @brief This returns the state as a vector<Part*> pointers
	/// @return vector<Part*>
	vector<Part*> getState();
};

#endif // !State_h