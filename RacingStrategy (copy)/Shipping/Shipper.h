#ifndef SHIPPER_H
#define SHIPPER_H

#include "HighPriority.h"
#include "../Container/LowPriority.h"

using namespace	std;

class Shipper{
private:
	LowPriority* lowPriority = 0;
	HighPriority* highPriority = 0;

public:
	Shipper();
	~Shipper();
	///@returns a reference to lowPriority
	LowPriority* getLowPriority();
	///@returns a reference to highPriority
	HighPriority* getHighPriority();
};

#endif