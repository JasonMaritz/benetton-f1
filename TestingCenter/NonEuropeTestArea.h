#ifndef NonEuropeTestArea_h
#define NonEuropeTestArea_h

#include "TestingCenter.h"
#include <fstream>

using namespace std;

class NonEuropeTestArea : public TestingCenter
{
public:
	void TestParts(bool Windtunnel, string TestName);
	void printTestReport(Part*, double, string TestName);

};

#endif // !NonEuropeTestArea_h