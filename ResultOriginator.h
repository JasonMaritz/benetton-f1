#ifndef RESULTORIGINATOR_H
#define RESULTORIGINATOR_H
#include "RaceResults.h"
#include "Times.h"

class ResultOriginator {

private:
	RaceResults state;
	Times* times;
public:
	///Runs through all the given cars in the field and determines total race results for them all
	RaceResults createResults();
	///If for some reason a different set of results exts, for instance apotential restore of past results, this would allow that restoration to occur
	///@param results Specifies the results being restored
	void setResults(RaceResults results);
};

#endif