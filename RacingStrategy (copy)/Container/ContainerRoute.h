#ifndef CONTAINERROUTE_H
#define CONTAINERROUTE_H

#include <string>
#include <vector>

#include "ContainerSet.h"
#include "Destination.h"
//#include "TransportMode.h"
#include "RouteIterator.h"

using namespace std;

class TransportMode;

class ContainerRoute{
private:
	ContainerSet* containers = 0; //Only 1 set. Not an array
	vector<Destination*> stops;
	TransportMode* transport =0;
	RouteIterator* currLocation =0;

	void clearRoute();
public:
	ContainerRoute();
	///Constructor
	/// @param a pointer to a ContainerSet, this is deep copied
	ContainerRoute(ContainerSet* c);
	~ContainerRoute();

	///Don't attempt to use routeIterator after its ContainerRoute has been destroyed
	/// @returns a pointer to a RouteIterator object, also transfers ownership of iterator
	RouteIterator* getRouteIterator();
	void decideTransportMode(); //used by LowPriority
	/// @param a pointer to a ContainerSet, this is deep copied
	void setContainers(ContainerSet* c);
	/// @returns a pointer to the containers (1 object)
	ContainerSet* getContainers();
	///@param a string that specifies the transport mode
	void setTransportMode(string mode); //used by HighPriority
	///@param A TransportMode object
	void setTransportMode(TransportMode* t );
	///@param a pointer to a vector of destination pointers, deep copied
	void setStops(vector<Destination*>* s);
	void printRoute();
	
	/// @todo calls the transports eta 
	void transportCargo();
	///@returns a Locationptr
	Location* getCurrLocation();
	///@returns a TransportMode ptr
	TransportMode* getTransportMode() const;
};

#endif
