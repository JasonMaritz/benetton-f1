#ifndef TestingCenter_h
#define TestingCenter_h

#include "../Parts/include/Part.h"
#include "WindTunnelCounter.h"
#include "Memento.h"
#include <vector>
#include <iostream>

using namespace std;

class Memento;
class WindTunnelCounter;

class TestingCenter
{
protected:
	vector<Part*> PartList;
	WindTunnelCounter* WTCounter;
	vector<Memento*> MementoList;

public:
	/// @brief Constructor which sets the WindTunnelCounter to a member. Note only one WindTunnelCounter should be made a season
	/// @param WTCounter is the WindTunnelCounter*
	TestingCenter(WindTunnelCounter* WTCounter);

	/// @brief This adds a new part to the text queue
	/// @param part is the part that will be added to the queue
	void addToTestQueue(Part* part);

	/// @brief This creates the memento
	/// @return Memento* that was created
	Memento* createMemento();

	/// @brief This sets the memento with given parameter
	/// @param m is the memento that will be set
	void setMemento(Memento* m);

	/// @brief This will test all the parts in the vector<Part*>. Pure virtual function
	/// @param WindTunnel this specifies if windtunnel or software test should be run
	/// @param TestName Name of test for textfile
	virtual void TestParts(bool windtunnel, string TestName)=0;

	/// @brief This will write the test report for a part to a textfile with a given performance
	/// @param prt is the part thats performance has to be written to specified textfile
	/// @param performance is the double value which is assigned its performance
	/// @param TestName is the textfiles name
	virtual void printTestReport(Part*, double, string TestName) = 0;
};
#endif // !TestingCenter_h
