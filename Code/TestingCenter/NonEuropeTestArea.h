#ifndef NonEuropeTestArea_h
#define NonEuropeTestArea_h

#include "TestingCenter.h"
#include <fstream>

using namespace std;

class NonEuropeTestArea : public TestingCenter
{
public:
	/// @brief This will test all the parts in the vector<Part*>
	/// @param WindTunnel this specifies if windtunnel or software test should be run
	/// @param TestName Name of test for textfile
	void TestParts(bool Windtunnel, string TestName);

	/// @brief This will write the test report for a part to a textfile with a given performance
	/// @param prt is the part thats performance has to be written to specified textfile
	/// @param performance is the double value which is assigned its performance
	/// @param TestName is the textfiles name
	void printTestReport(Part*, double, string TestName);

};

#endif // !NonEuropeTestArea_h