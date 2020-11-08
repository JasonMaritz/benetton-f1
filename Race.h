#ifndef RACE_H
#define RACE_H
#include <vector>
#include <string>
#include "RaceResults.h"
#include "Track.h"
#include "ContainerSet.h"
#include "ContainerRoute.h"
#include "PackedItem.h"
#include "Times.h"
#include "Tyre.h"
#include "MediumTyre.h"
#include "HardTyre.h"
#include "SoftTyre.h"

class Race {

private:
	Times* times;
	ResultOriginator* resultOriginator;
	RaceStrategy::RacingStrategy* raceStrategy;
	Track* track;
	ContainerSet* containerSet;
	std::vector<RaceResults> results;

public:
	///Create a race in whcih the constructor fetches the necessary containers to run the race
	Race();
	///Create the rac with the necessary parameters to run the race
	Race(RaceStrategy::RacingStrategy* RacingStrategy, Track* Track);
	///Break up the container given by the Strategy so that our car can be generated for the race
	///@param c The container which is going to be turned into a vector of parts from which our car will be built
	std::vector<Part*> breakContainer(ContainerSet* c);
	std::vector<Tyre*> breakContainerTyres(ContainerSet* c);
	void generateResults();
};

#endif
