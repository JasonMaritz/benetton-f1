
#include "Truck.h"

time_t Truck::eta(Location aDestination) {
	struct tm * eta ;

	int size = aDestination.name.length() ;

	double timetaken = size / this->speed ;

	eta->tm_mday = size ; 

	return mktime(eta) ;
}

Truck::Truck(  Location aDest, ContainerRoute* r,int a):TransportMode(aDest,r,a) {
}

void Truck::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if ( !this->getDestination().european ){ //not a european race
		//gets on a plane or ship 
		if (a )//true ==high prio
		{
			TransportMode* newP =  new ChartedPlane(getDestination(),_route) ;
			_route->setTransportMode(newP) ;
		}
		else{
			 TransportMode* ship = new Ship(this->getDestination(),_route) ;
			 _route->setTransportMode(ship) ;
		}
		
	}
}

