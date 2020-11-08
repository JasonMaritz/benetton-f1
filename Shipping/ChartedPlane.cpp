#include <exception>
#include <string>
using namespace std;

#include "ChartedPlane.h"

ChartedPlane::ChartedPlane( Location aCurr, ContainerRoute* r,int a):TransportMode(aCurr,r,a) {
	// default speed for plane is 200km/h
}

time_t ChartedPlane::eta(Location aDestination) {
	throw "Not yet implemented";
}

void ChartedPlane::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if (_route != NULL){
		TransportMode* newT = new Truck(this->getDestination(),_route,speed-20) ; //plane to truck
		newT->setOnRoute(true) ;
		_route->setTransportMode(newT) ;
	}
	
}

