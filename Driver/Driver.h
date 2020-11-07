#ifndef Driver_h
#define Driver_h

#include <string>
#include "../Simulation/Result.h"

using namespace std;

class Driver
{
private:
	string Name;
	Result* result;

public:
	Driver(string name);
	void generateReport();
	void setResult(Result* result);
};


#endif // !Driver_h