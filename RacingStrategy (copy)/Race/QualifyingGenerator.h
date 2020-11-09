#ifndef QUALIFYINGGENERATOR_H
#define QUALIFYINGGENERATOR_H
#include "TimeGenerator.h"
#include "RaceGenerator.h"

class QualifyingGenerator : public TimeGenerator {


public:
	void handleChanges(Times* context);
	///Get an array of times for the entire field's qualifying times
	///@param car Our car which is then compared to a normalised set of others
	float* getTime(F1Car* car);
};

#endif
