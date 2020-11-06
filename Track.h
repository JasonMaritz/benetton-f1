#ifndef Track_h
#define Track_h

#include "Result.h"

class Track
{
private:
	Result* result;

public:
	void setResult(Result* result);
	void generateReport();
};

#endif // !Track_h

