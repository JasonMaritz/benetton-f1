#ifndef Car_h
#define Car_h

#include "Result.h"

class Car
{
private:
	Result* result;

public:
	void setResult(Result* result);
	void generateReport();
};

#endif // !Car_h

