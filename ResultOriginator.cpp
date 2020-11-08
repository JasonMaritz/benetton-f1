#include "ResultOriginator.h"

RaceResults ResultOriginator::createResults() {
	RaceResults r = new RaceResults();
	float[3] results;
	for (int i = 0; i < 3; i++) 	// for each car in the race, we need to generate results
	{
		r.setState(times->getTime(), i);
		times->change();
	}
	return r;
}

void ResultOriginator::setResults(RaceResults results) {
	// TODO - implement ResultOriginator::setResults
	throw "Not yet implemented";
}

// PLAN : CREATE A 2D ARRAY - 1 DIMENSION IS RACE, THE NEXT IS DRIVER/CAR