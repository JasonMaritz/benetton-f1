#ifndef CONTAINERROUTE_H
#define CONTAINERROUTE_H

#include <string>
#include <vector>
#include <iostream>

class TransportMode ;

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
	TransportMode* transport ; 
	RouteIterator* currLocation;


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
	ContainerSet* getContainers() const;
	///@param a string that specifies the transport mode
	void setTransportMode(string mode); //used by HighPriority
	///@param a pointer to a vector of destination pointers, deep copied
	void setStops(vector<Destination*>* s);
	void printRoute();

	void transportCargo() ; //makes request to tranport
	
	/// @returns a pointer to a TransportMode, will return NULL if not set assigned a Concrete TransportMode
	TransportMode* getTransportMode() const ;
	/// @param a pointer to a TransportMode Concrete object
	void setTransportMode(TransportMode* t ) ;
	
	Location* getCurrLocation() ;
};

#endif

#include "../Shipping/TransportMode.h"
