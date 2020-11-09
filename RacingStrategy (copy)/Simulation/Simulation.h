#ifndef Simulation_h
#define Simulation_h

#include "../Strategy/RacingStrategyInterface.h"
#include "../Driver/Driver.h"
#include "../Track/Track.h"
#include "../F1Car/include/F1Car.h"
#include "../Parts/include/Part.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

class Simulation
{
private:
	RacingStrategyInterface* RaceStrat;
	Driver* driver;
	Track* track;
	F1Car* car;
	vector<Part*> PartsList;
	string UniqueID;
	bool checkValid();
	bool hasRun;

public:
	Simulation(string UniqueID);
	void setRaceStrat(RacingStrategyInterface* RaceStrat);
	void setDriver(Driver* driver);
	void setTrack(Track* track);
	void setPartsBuildCar(vector<Part*> list);
	Result* RunSimulate();
	bool hasSimulationRun();
	void printLog(string msg);
};

#endif // !Simulation

