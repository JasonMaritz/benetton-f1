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
	if (engineering == nullptr) { return false; }
	return true;
}

Simulation::Simulation(string UniqueID)
{
	RaceStrat = NULL;
	driver = NULL;
	track = NULL;
	car = NULL;
	engineering = NULL;
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
	if (!isInOurParts("ice", list))
	{
		Engine* engine = this->engineering->getEngine();
		Part* newPart = engine->makePart("ice");
		list.push_back(newPart);
	}

	if (!isInOurParts("turbocharger", list))
	{
		Engine* engine = this->engineering->getEngine();
		Part* newPart = engine->makePart("turbocharger");
		list.push_back(newPart);
	}

	if (!isInOurParts("mguk", list))
	{
		Electronics* electronics = this->engineering->getElectronics();
		Part* newPart = electronics->makePart("mguk");
		list.push_back(newPart);
	}

	if (!isInOurParts("mguh", list))
	{
		Electronics* electronics = this->engineering->getElectronics();
		Part* newPart = electronics->makePart("mguh");
		list.push_back(newPart);
	}

	if (!isInOurParts("energystore", list))
	{
		Electronics* electronics = this->engineering->getElectronics();
		Part* newPart = electronics->makePart("energystore");
		list.push_back(newPart);
	}

	if (!isInOurParts("ers", list))
	{
		Electronics* electronics = this->engineering->getElectronics();
		Part* newPart = electronics->makePart("ers");
		list.push_back(newPart);
	}

	if (!isInOurParts("chassis", list))
	{
		Chassis* chassis = this->engineering->getChassis();
		Part* newPart = chassis->makePart("chassis");
		list.push_back(newPart);
	}

	if (!isInOurParts("drs", list))
	{
		Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
		Part* newPart = aerodynamics->makePart("drs");
		list.push_back(newPart);
	}

	if (!isInOurParts("bargeboard", list))
	{
		Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
		Part* newPart = aerodynamics->makePart("bargeboard");
		list.push_back(newPart);
	}

	this->PartsList = list;
	RaceBuilderDir* RBD = new RaceBuilderDir();
	car = RBD->buildCar(list);
	printLog("Parts list has been set for simulation: " + UniqueID);
	printLog("Car has been build with given parts for sumulation: " + UniqueID);
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
	try {
		car->generateReport();
	}
	catch (...)
	{}
	hasRun = true;
	return result;
}

bool Simulation::hasSimulationRun()
{
	return hasRun;
}

void Simulation::printLog(string msg)
{
	ofstream tf(UniqueID + "Log.txt", ios::app);
	tf << msg;
	tf << endl;
	tf.close();
}

void Simulation::setEngineering(Engineering* eng)
{
	engineering = eng;
}

bool Simulation::isInOurParts(string partName, vector<Part*> ourParts)
{
	vector<Part*>::iterator it;
	for (it = ourParts.begin(); it < ourParts.end(); it++)
	{
		Part* temp = (Part*)((*it));
		stringstream ss(temp->getType());
		string to;
		getline(ss, to, ' ');
		if (to == partName)
		{
			return true;
		}
	}
	return false;
}