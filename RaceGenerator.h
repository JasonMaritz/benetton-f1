#ifndef RACEGENERATOR_H
#define RACEGENERATOR_H
#include "TimeGenerator.h"

class RaceGenerator : public TimeGenerator {


public:
	///Alter the state of the Times class to reflect the correct race session
	///@param context Defines the Times class we are setting te session for
	void handleChanges(Times* context);

	/// Get an array of times representing the entire field of cars in the race
	///@param car Defines the car which is being fielded by our team for this particular race - will be used to determine how we place
	///@return Returns an array of floats dictating the cars' race times for the race as a whole
	float* getTime(F1Car* car);
};

#endif
