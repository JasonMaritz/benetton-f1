#ifndef EuropeTestArea_h
#define EuropeTestArea_h

#include "TestingCenter.h"

using namespace std;

class EuropeTestArea : public TestingCenter
{
public:
	/// @brief This will test all the parts in the vector<Part*>
	/// @param WindTunnel this specifies if windtunnel or software test should be run
	/// @param TestName Name of test for textfile
	void TestParts(bool WindTunnel, string TestName);

	/// @brief This will write the test report for a part to a textfile with a given performance
	/// @param prt is the part thats performance has to be written to specified textfile
	/// @param performance is the double value which is assigned its performance
	/// @param TestName is the textfiles name
	void printTestReport(Part* prt, double performance, string TestName);
};

#endif // !EuropeTestArea_h

