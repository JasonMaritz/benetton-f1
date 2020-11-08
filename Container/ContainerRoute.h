#ifndef CONTAINERROUTE_H
#define CONTAINERROUTE_H

#include <string>
#include <vector>
class TransportMode;
// class Truck ;

#include "ContainerSet.h"
#include "Destination.h"
#include "RouteIterator.h"
// #include "../Shipping/TransportMode.h"
// #include "../Shipping/Truck.h"

using namespace std;


class ContainerRoute{
private:
	ContainerSet* containers = 0; //Only 1 set. Not an array
	vector<Destination*> stops;
	TransportMode* transport ; 
	RouteIterator* currLocation;


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
	void setTransportMode(int mode); //used by HighPriority
	void setStops(vector<Destination*>* s); //Makes deep copy
	void transportCargo() ; //makes request to tranport
	ContainerSet* getContainers() const ;
	TransportMode* getTransportMode() const ;
	void setTransportMode(TransportMode* t ) ;
	Location* getCurrLocation() ;
 };

#endif

#include "../Shipping/TransportMode.h"
