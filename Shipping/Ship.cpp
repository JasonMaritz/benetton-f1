#include <exception>
#include <string>
using namespace std;

#include "Ship.h"

Ship::Ship( Location aDest, ContainerRoute* r,int a=65):TransportMode(aDest,r,a) {
}

time_t Ship::eta(Location aDestination) {
	throw "Not yet implemented";
}

void Ship::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if (_route != NULL){
		TransportMode* newT = new Truck(getDestination(),_route,speed+15) ;
		_route->setTransportMode(newT) ;
	}
}

