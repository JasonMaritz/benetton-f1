#ifndef SHIPPER_H
#define SHIPPER_H

#include "HighPriority.h"
#include "../Container/LowPriority.h"

using namespace	std;

class Shipper
{
private:
	LowPriority* lowPriority = nullptr;
	HighPriority* highPriority = nullptr;
    static Shipper* instance;
    Shipper();

public:
	///@returns the only instance of Shipper
    static Shipper* getInstance();
	~Shipper();
	///@returns a reference to lowPriority
	LowPriority* getLowPriority();
	///@returns a reference to highPriority
	HighPriority* getHighPriority();
};

#endif
