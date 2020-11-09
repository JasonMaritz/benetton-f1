
#include "Truck.h"

time_t Truck::eta(Location aDestination) {

	cout<<"---Truck just left the loading dock\n" ;
	struct tm * eta ;

	int size = aDestination.name.length() ;

	int timetaken = size *100 / this->speed ;

	eta->tm_mday = timetaken % 7 ; 

	std::time_t t = timetaken ;
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
		}
		else{
			cout<<"--Loading cargo to the Plane\n" ;
			 TransportMode* ship = new Ship(this->getDestination(),_route) ;
			 ship->setRoute(_route) ;
			 _route->setTransportMode(ship) ;
		}
		
	}
	else{
		cout<<"--ofloading Cargo being transported by Truck\n" ;
	}
}

