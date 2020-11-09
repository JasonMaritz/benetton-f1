#include <exception>
#include <string>
using namespace std;

#include "Ship.h"

Ship::Ship( Location aDest, ContainerRoute* r,int a):TransportMode(aDest,r,a) {
}

time_t Ship::eta(Location aDestination) {
	// throw "Not yet implemented";

	struct tm * eta ;

	int size = aDestination.name.length() ;

	int timetaken = size * 100/ this->speed ;

	eta->tm_mon = size % 4 ; 

	 mktime(eta) ;
	std::time_t t = timetaken ;
	return t ;
}

void Ship::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if (_route != NULL){
		TransportMode* newT = new Truck(getDestination(),_route,speed+15) ;
		_route->setTransportMode(newT) ;
	}
}

