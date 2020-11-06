#include "TestingCenter.h"

TestingCenter::TestingCenter(WindTunnelCounter* WTCounter)
{
	this->WTCounter = WTCounter;
}

void TestingCenter::addToTestQueue(Parts* part)
{
	if (part != NULL)
	{
		PartList.push_back(part);
		cout << "Added to back" << endl;
	}
	else {
		cout << "Testing center supplied part was incorrect" << endl;
	}
}

Memento* TestingCenter::createMemento()
{
	Memento* m = new Memento();
	m->setState(PartList);
	MementoList.push_back(m);
	return m;
}

void TestingCenter::setMemento(Memento* m)
{
	PartList = m->getState();
}
