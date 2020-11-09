#ifndef PRACTICEGENERATOR_H
#define PRACTICEGENERATOR_H
#include "TimeGenerator.h"
#include "QualifyingGenerator.h"
#include <time.h>
#include <cstdlib>

class PracticeGenerator : public TimeGenerator {


public:
	void handleChanges(Times* context) override;

	///Get an array of times for the entire field's practice times
	///@param car Our car which is then compared to a normalised set of others
	///@return Returns an array of times for the entire field, with our specific car in spaces 19 and 20 in the times array
	float* getTime(F1Car* car) override;
};

#endif
