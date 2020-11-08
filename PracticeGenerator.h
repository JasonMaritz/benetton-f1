#ifndef PRACTICEGENERATOR_H
#define PRACTICEGENERATOR_H
#include "TimeGenerator.h"
#include "QualifyingGenerator.h"

class PracticeGenerator : public TimeGenerator {


public:
	void handleChanges(Times* context);

	///Get an array of times for the entire field's practice times
	///@param car Our car which is then compared to a normalised set of others
	float* getTime(F1Car* car);
};

#endif
