#include <exception>
#include <string>

using namespace std;

#include "ChartedPlane.h"

ChartedPlane::ChartedPlane( Location aCurr, ContainerRoute* r,int a):TransportMode(aCurr,r,a) {
	// default speed for plane is 200km/h
}

time_t ChartedPlane::eta(Location aDestination) {
	
	struct tm * eta ;

	int size = aDestination.name.length() ;

	int timetaken = size *100 / this->speed ;

	eta->tm_hour = size % 24 ; 

	// return mktime(eta) ;
	
	std::time_t t = timetaken ;
	return t ;
}

void ChartedPlane::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if (_route != NULL){
		TransportMode* newT = new Truck(this->getDestination(),_route,speed-20) ; //plane to truck
		newT->setOnRoute(true) ;
		_route->setTransportMode(newT) ;
	}
	
}

