#include "Simulation.h"

using namespace std;
//ADD TEXTFILE fun

bool Simulation::checkValid()
{
	if (!RaceStrat) { return false; }
	if (!driver) { return false; }
	if (!track) { return false; }
	if (!car) { return false; }
	if (PartsList.empty()) { return false; }
	if (UniqueID.length() <= 0) { return false; }
	return true;
}

Simulation::Simulation(string UniqueID)
{
	RaceStrat = NULL;
	driver = NULL;
	track = NULL;
	car = NULL;
	this->UniqueID = UniqueID;
}

void Simulation::setRaceStrat(RacingStrategyInterface* RaceStrat)
{
	this->RaceStrat = RaceStrat;
	printLog("Race Strategy has been set for simulation: " + UniqueID);
}

void Simulation::setDriver(Driver* driver)
{
	this->driver = driver;
	printLog("Driver has been set for simulation: " + UniqueID);
}

void Simulation::setTrack(Track* track)
{
	this->track = track;
	printLog("Track has been set for simulation: " + UniqueID);
}

void Simulation::setPartsBuildCar(vector<Part*> list)
{
	
}

Result* Simulation::RunSimulate()
{
	if (!checkValid())
	{
		throw "Simulation not correctly configured";
		return NULL;
	}
	Result* result = new Result();
	RaceStrat->setResult(result);
	driver->setResult(result);
	track->setResult(result);
	car->setResult(result);

	RaceStrat->generateReport();
	driver->generateReport(track);
	track->generateReport();
	car->generateReport();
	hasRun = true;
	return result;
}

bool Simulation::hasSimulationRun()
{
	return hasRun;
}

void Simulation::printLog(string msg)
{
	ofstream tf(UniqueID + "Log.txt");
	tf << msg;
	tf << endl;
	tf.close();
}
