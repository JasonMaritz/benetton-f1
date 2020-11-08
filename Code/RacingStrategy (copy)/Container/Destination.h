#ifndef DESTINATION_H
#define DESTINATION_H

#include <ctime>

#include "Location.h"

using namespace std;

class Destination{
public:
	time_t startDate;
	time_t endDate;
	Location location;

	Destination();
	Destination(Destination*);
};

#endif