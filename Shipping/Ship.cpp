#include <exception>
#include <string>
using namespace std;

#include "Ship.h"

Ship::Ship( Location aDest, ContainerRoute* r,int a):TransportMode(aDest,r,a) {
}

time_t Ship::eta(Location aDestination) {
	// throw "Not yet implemented";
	cout<<"---Ship just left the harbor \n" ;
	struct tm * eta ;

	int size = aDestination.name.length() ;

	long timetaken = size * 100/ this->speed ;

	eta->tm_mon = (timetaken % 4) *30 ; 
	
	std::time_t t = timetaken ; //mktime(eta) ;
	return t ;
}

void Ship::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if (_route != NULL){
		cout<<"--Offloading to the Truck\n" ;
		TransportMode* newT = new Truck(getDestination(),_route,speed+15) ;
		newT->setRoute(_route) ;
		_route->setTransportMode(newT) ;
	}
}

