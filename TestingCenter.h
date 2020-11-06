#ifndef TestingCenter_h

#include "Parts.h"
#include "WindTunnelCounter.h"
#include "Memento.h"
#include <vector>
#include <iostream>

using namespace std;

class TestingCenter
{
protected:
	vector<Parts*> PartList;
	WindTunnelCounter* WTCounter;
	vector<Memento*> MementoList;

public:
	TestingCenter(WindTunnelCounter* WTCounter);
	void addToTestQueue(Parts* part);
	Memento* createMemento();
	void setMemento(Memento* m);
	virtual void  TestParts()=0;
};
#endif // !TestingCenter_h
