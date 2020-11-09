#ifndef LOWPRIORITY_H
#define LOWPRIORITY_H

#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

#include "Destination.h"
#include "ContainerRoute.h"

using namespace std;

class LowPriority{
private:
	vector<Destination*> destinations;
	vector<ContainerRoute*> routes;
	ContainerSet* prototypeContainer = 0;

	///@param data in dd-mm-yyyy format
	///@returns The corresponding date in time_t format
	time_t timetFromStr(string date);
	///@param vec A reference to a Destination* vector
	///@param byStart a boolean that represents if they should be sorted by start or end dates
	void orderDestinations(vector<Destination*>& vec, bool byStart);

public:
	void setupRoutes();
	///@param d An array of destinations (not ptrs to destinations)
	///@param nDestinations Number of destinations in array
	void setDestinations(Destination* d, int nDestinations); //Array of Destinations (not ptrs)
	///@param p A pointer to a ContainerSet, deep copied
	void setPrototype(ContainerSet* p);
	int getNumRoutes();
	///@param index of route to be returned
	///@returns a pointer to a ContainerRoute
	ContainerRoute* getRoute(int index);
	void destinationsFromtxt();
	void printRoutes();
    string getDestinations();
};

#endif
