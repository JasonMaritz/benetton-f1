#ifndef TIMEGENERATOR_H
#define TIMEGENERATOR_H
#include "Track.h"
#include "Times.h"
#include "F1Builder.h"

class TimeGenerator {

private:
	Track* track;
	void setTrack(Track*);

public:
	///Alters the session being used by the Times class
	virtual void handleChanges(Times* context) = 0;
	///Fetches the time being created in the session by each car in the car list
	///@param car Specifies our car from which times will be generated
	virtual float* getTime(F1Car* car) = 0;
};

#endif