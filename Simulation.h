#ifndef Simulation_h
#define Simulation_h

#include "RaceStrategy.h"
#include "Driver.h"
#include "Track.h"
#include "Car.h"
#include "Parts.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation
{
private:
	RaceStrategy* RaceStrat;
	Driver* driver;
	Track* track;
	Car* car;
	vector<Parts*> PartsList;
	string UniqueID;

public:
	Simulation(string UniqueID);
	void setRaceStrat(RaceStrategy* RaceStrat);
	void setDriver(Driver* driver);
	void setTrack(Track* track);
	void setPartsBuildCar(vector<Parts*> list);
	Result* RunSimulate();

};

#endif // !Simulation

