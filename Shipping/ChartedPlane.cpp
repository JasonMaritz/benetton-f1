#include <exception>
#include <string>

using namespace std;

#include "ChartedPlane.h"

ChartedPlane::ChartedPlane( Location aCurr, ContainerRoute* r,int a):TransportMode(aCurr,r,a) {
	// default speed for plane is 200km/h
}

time_t ChartedPlane::eta(Location& aDestination) {
	
	cout<<"---Plane just took of. \n" ;

	struct tm * eta ;

	int size = aDestination.name.length() ;

	long timetaken = size *100 / this->speed ;
	
	std::time_t t = timetaken ; //mktime(eta) ;
	return t ;
}

void ChartedPlane::changeTransportMode(bool a = false) {
	if (_route != NULL){
		cout<<"--Offloading to the Truck\n" ;
		TransportMode* newT = new Truck(this->getDestination(),_route,speed-20) ; //plane to truck
		newT->setOnRoute(true) ;
		_route->setTransportMode(newT) ;
		newT->setOnRoute(false) ;
	}
	
}

