#ifndef Simulation_h
#define Simulation_h

#include "../Strategy/RacingStrategy.h"
#include "../Driver/Driver.h"
#include "../Track/Track.h"
#include "../F1Car/include/F1Car.h"
#include "../Parts/include/Part.h"
#include <vector>
#include <iostream>
#include <string>

class Simulation
{
private:
	RacingStrategy* RaceStrat;
	Driver* driver;
	Track* track;
	F1Car* car;
	vector<Part*> PartsList;
	string UniqueID;

public:
	Simulation(string UniqueID);
	void setRaceStrat(RacingStrategy* RaceStrat);
	void setDriver(Driver* driver);
	void setTrack(Track* track);
	void setPartsBuildCar(vector<Part*> list);
	Result* RunSimulate();

};

#endif // !Simulation

