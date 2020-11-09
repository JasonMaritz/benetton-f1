#ifndef LOWPRIORITY_H
#define LOWPRIORITY_H

#include <vector>
#include <list>
#include <string>
#include <fstream>

#include "Destination.h"
#include "ContainerRoute.h"

using namespace std;

class LowPriority{
private:
	vector<Destination*> destinations;
	vector<ContainerRoute*> routes;
	ContainerSet* prototypeContainer = 0;

	///@param in dd-mm-yyyy format
	///@returns The corresponding date in time_t format
	time_t timetFromStr(string date);
	///@param A reference to a Destination* vector
	///@param a boolean that represents if they should be sorted by start or end dates
	void orderDestinations(vector<Destination*>& vec, bool byStart);

public:
	void setupRoutes();
	///@param An array of destinations (not ptrs to destinations)
	///@param Number of destinations in array
	void setDestinations(Destination*, int nDestinations); //Array of Destinations (not ptrs)
	///@A pointer to a ContainerSet, deep copied
	void setPrototype(ContainerSet* p);
	int getNumRoutes();
	///@param index of route to be returned
	///@returns a pointer to a ContainerRoute
	ContainerRoute* getRoute(int index);
	///@param The filename for where destinations are to be read from
	void destinationsFromtxt(string filename);
	void printRoutes();
};

#endif