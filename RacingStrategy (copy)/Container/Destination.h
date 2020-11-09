#ifndef DESTINATION_H
#define DESTINATION_H

#include <ctime>

#include "Location.h"

using namespace std;

class Destination
{
public:
	time_t startDate;
	time_t endDate;
	Location location;

	Destination();
	///@param reference to Destination to make copy of
	Destination(Destination*);
};

#endif