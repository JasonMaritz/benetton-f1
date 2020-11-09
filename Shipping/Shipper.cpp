#include "Shipper.h"

Shipper::Shipper() {
	lowPriority = new LowPriority();
	highPriority = new HighPriority();
}

Shipper::~Shipper() {
	delete lowPriority;
	delete highPriority;
}

LowPriority* Shipper::getLowPriority() {
	return lowPriority;
}

HighPriority* Shipper::getHighPriority() {
	return highPriority;
}