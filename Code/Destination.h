#ifndef DESTINATION_H
#define DESTINATION_H

#include <ctime>

#include "Location.h"

using namespace std;

class Destination{
public:
	time_t date;
	Location location;

	Destination(Destination*);
};

#endif