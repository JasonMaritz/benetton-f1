#ifndef LOWPRIORITY_H
#define LOWPRIORITY_H

#include <vector>
#include <list>

#include "Destination.h"
#include "ContainerRoute.h"

using namespace std;

class LowPriority{
private:
	vector<Destination*> destinations;
	vector<ContainerRoute*> routes;
	ContainerSet* prototypeContainer = 0;

	void orderDestinations(vector<Destination*>& vec, bool byStart);

public:
	void setupRoutes();

	void setDestinations(Destination*, int nDestinations); //Array of Destinations (not ptrs)
	void setPrototype(ContainerSet* p); //Makes deep copy
};

#endif