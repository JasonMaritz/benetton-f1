#include "WindTunnelCounter.h"

double WindTunnelCounter::runWTTest(Part* prt, int offset)
{
	if (TestsLeft - 1 >= 0)
	{
		TestsLeft--;
		return prt->getPerformance() + prt->getPerformance() * 0.1 - prt->getPerformance() * offset / 100.0;
	}
	else {
		throw "Wind tunnel tests exceded";
	}
}

int WindTunnelCounter::getTestsLeft()
{
	return TestsLeft;
}
