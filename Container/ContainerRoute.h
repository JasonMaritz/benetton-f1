#ifndef CONTAINERROUTE_H
#define CONTAINERROUTE_H

#include <string>
#include <vector>

#include "ContainerSet.h"
#include "Destination.h"
//#include "TransportMode.h"
#include "RouteIterator.h"

using namespace std;

class ContainerRoute{
private:
	ContainerSet* containers = 0; //Only 1 set. Not an array
	vector<Destination*> stops;
	//TransportMode
	Location currLocation;

	void clearRoute();
public:
	ContainerRoute();
	ContainerRoute(ContainerSet* c);//Makes deep copy
	~ContainerRoute();

	//Don't attempt to use routeIterator after its
	//ContainerRoute has been destroyed
	RouteIterator* getRouteIterator();
	void decideTransportMode(); //used by LowPriority
	void setContainers(ContainerSet* c); //Makes deep copy
	ContainerSet* getContainers();
	void setTransportMode(string mode); //used by HighPriority
	void setStops(vector<Destination*>* s); //Makes deep copy
	void printRoute();
};

#endif