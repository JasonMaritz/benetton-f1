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

	/// @brief Simulation constructor
	/// @param UniqueID simulation unique ID
	Simulation(string UniqueID);

	/// @brief Sets the RacingStrategyInterface member. Needed to RunSimulation
	/// @param RaceStrat for RacingStrategyInterface member
	void setRaceStrat(RacingStrategyInterface* RaceStrat);

	/// @brief Sets the Driver member. Needed to RunSimulation
	/// @param driver for Driver member
	void setDriver(Driver* driver);

	/// @brief Sets the Track member. Needed to RunSimulation
	/// @param track for Track member
	void setTrack(Track* track);

	/// @brief Sets the Parts list to build a car. Needed to RunSimulation
	/// @param list of Parts used to build a car
	void setPartsBuildCar(vector<Part*> list);

	/// @brief Runs the simulation. Will throw a string if all members have not been set
	/// @return Result* which has all the simulation results stored
	Result* RunSimulate();

	/// @brief Gets function for bool to see if simulation has been run
	/// @return if the simulation has been run
	bool hasSimulationRun();

	/// @brief Used to write a message to the log file of the simulation with the UniqueID as textfile name
	/// @param msg String containing message for log file
	void printLog(string msg);
};

#endif // !Simulation

