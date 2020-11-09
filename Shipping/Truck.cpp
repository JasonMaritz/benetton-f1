
#include "Truck.h"

time_t Truck::eta(Location& aDestination) {

	cout<<"---Truck just left the loading dock\n" ;
	this->setOnRoute(true) ;

	int size = aDestination.name.length() ;

	int timetaken = size *100 / this->speed ;

	std::time_t t = timetaken * 7  ;
	return t ;
}

Truck::Truck(  Location aDest, ContainerRoute* r,int a):TransportMode(aDest,r,a) {
}

void Truck::changeTransportMode(bool a = false) {
	// throw "Not yet implemented";
	if ( !this->getDestination().european ){ //not a european race
		//gets on a plane or ship 
		if (a )//true ==high prio
		{
			cout<<"--Loading cargo to the Plane\n" ;
			TransportMode* newP =  new ChartedPlane(getDestination(),_route) ;
			newP->setRoute(_route) ;
			_route->setTransportMode(newP) ;
			newP->setOnRoute(false) ;
		}
		else{
			cout<<"--Loading cargo to the Plane\n" ;
			 TransportMode* ship = new Ship(this->getDestination(),_route) ;
			 ship->setRoute(_route) ;
			 _route->setTransportMode(ship) ;
			 ship->setOnRoute(false) ;
		}
	}
	else{
		cout<<"--ofloading Cargo being transported by Truck\n" ;
		this->setOnRoute(false) ;
	}
}

