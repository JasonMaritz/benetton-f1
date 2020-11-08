#include "ResultOriginator.h"

RaceResults ResultOriginator::createResults() {
	RaceResults r = new RaceResults();
	float[3] results;
	for (int i = 0; i < 3; i++) 	// for each session in the race, we need to generate results
	{
		r.setState(times->getTime(), i);
		times->change();
	}
	return r;
}

void ResultOriginator::setResults(RaceResults results) {
	this->state = results;
}