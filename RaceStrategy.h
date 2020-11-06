#ifndef RaceStrategy_h
#define RaceStrategy_h

#include "Result.h"

class RaceStrategy
{
private:
	Result* result;

public:
	void setResult(Result* result);
	void generateReport();

};

#endif // !RaceStrategy_h

