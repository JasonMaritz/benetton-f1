#ifndef EuropeTestArea_h
#define EuropeTestArea_h

#include "TestingCenter.h"

using namespace std;

class EuropeTestArea : public TestingCenter
{
public:
	void TestParts(bool WindTunnel, string TestName);
	void printTestReport(Part*, double, string TestName);
};

#endif // !EuropeTestArea_h

