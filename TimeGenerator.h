#ifndef TIMEGENERATOR_H
#define TIMEGENERATOR_H
#include "Track.h"
#include "Times.h"
#include "F1Builder.h"
#include "F1Car.h"

class TimeGenerator {

protected:
	Track* track;

public:
	///Alters the session being used by the Times class
	virtual void handleChanges(Times* context) = 0;
	///Fetches the time being created in the session by each car in the car list
	///@param car Specifies our car from which times will be generated
	virtual float* getTime(F1Car* car) = 0;

	///Set the track on which the calculations wil be based
	///@param track The track which will be used by the calculations
	void setTrack(Track* track);
};

#endif