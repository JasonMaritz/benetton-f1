#ifndef WindTunnelTest_h
#define WindTunnelTest_h

#include "../Parts/include/Part.h"

class Part;

class WindTunnelCounter
{
private:
	int TestsLeft = 400;

public:
	/// @brief Runs a windtunnel test. If TestsLeft < 400 an exception will be thrown
	/// @param prt is the part that will be tested
	/// @param offset is the offsett used for the test
	/// @return the result of the test
	double runWTTest(Part* prt, int offset);

	/// @brief This will return the tests left for the season
	/// @return TestsLeft which is an integer
	int getTestsLeft();
};

#endif // !WindTunnelTest_h

