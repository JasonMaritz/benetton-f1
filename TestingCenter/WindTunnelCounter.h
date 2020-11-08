#ifndef WindTunnelTest_h
#define WindTunnelTest_h

#include "../Parts/include/Part.h"

class WindTunnelCounter
{
private:
	int TestsLeft = 400;

public:
	double runWTTest(Part* prt, int offset);
	int getTestsLeft();
};

#endif // !WindTunnelTest_h

