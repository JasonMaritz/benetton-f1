#include "Simulation.h"

using namespace std;

Simulation::Simulation(string UniqueID)
{
	RaceStrat = NULL;
	driver = NULL;
	track = NULL;
	car = NULL;
	this->UniqueID = UniqueID;
}

void Simulation::setRaceStrat(RaceStrategy* RaceStrat)
{
	this->RaceStrat = RaceStrat;
	cout << "Race Strategy has been set for simulation: " + UniqueID << endl;
}

void Simulation::setDriver(Driver* driver)
{
	this->driver = driver;
	cout << "Driver has been set for simulation: " + UniqueID << endl;
}

void Simulation::setTrack(Track* track)
{
	this->track = track;
	cout << "Track has been set for simulation: " + UniqueID << endl;
}

void Simulation::setPartsBuildCar(vector<Parts*> list)
{
	
}

Result* Simulation::RunSimulate()
{
	Result* result = new Result();
	if (driver) { driver->setResult(result);}
	else 
	{ 
		cout << "Driver is null" << endl;
		return NULL;
	}

	if (RaceStrat) { RaceStrat->setResult(result); }
	else
	{
		cout << "Race Strategy is null" << endl;
		return NULL;
	}

	if (track) { track->setResult(result); }
	else
	{
		cout << "Track is null" << endl;
		return NULL;
	}

	if (PartsList.empty)
	{
		cout << "Parts list is empty" << endl;
		return NULL;
	}
	else
	{
	//build car here
	}

	return result;
}
