#include "Shipper.h"

Shipper* Shipper::instance = nullptr;
Shipper *Shipper::getInstance()
{
    if(!instance)
    {
        instance = new Shipper();
    }
    return instance;
}

Shipper::Shipper()
{
    lowPriority = new LowPriority();
    highPriority = new HighPriority();
}

Shipper::~Shipper()
{
	delete lowPriority;
	delete highPriority;
}

LowPriority* Shipper::getLowPriority()
{
	return lowPriority;
}

HighPriority* Shipper::getHighPriority()
{
	return highPriority;
}
