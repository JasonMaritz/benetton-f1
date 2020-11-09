#include <iostream>
using namespace std ;

#include <ctime>
#include <fstream>

#include "Container/LowPriority.h"


// #include "Shipping/ChartedPlane.h"
#include "Shipping/HighPriority.h"
#include "Shipping/TransportMode.h"
#include "Container/ContainerRoute.h"
#include "Container/ContainerSet.h"
// #include "Container/ContainerRoute.h"
// #include "Container/Destination.h"
// #include "Container/Location.h"


void testLowPriority2() {
	cout << "Routes for low priority containers (each line a new set of containers):\n";
	LowPriority lp;
	lp.destinationsFromtxt("Data/Destinations.txt");
	lp.setupRoutes();
	lp.printRoutes();

}

int main(){

    // testLowPriority2() ;

    ContainerSet* package1 = new ContainerSet() ;
    ContainerRoute* route1 = new ContainerRoute(package1) ;

    HighPriority* priorityShipment1 = new HighPriority() ;
    Destination* dest1 = new Destination() ;
    Location* loc1 = new Location() ;
    loc1->name = "ASIA" ;
    dest1->location = *loc1 ;

	// public: void shipSomething(Destination* aDest, ContainerSet* aContainers, string aName);
    priorityShipment1->shipSomething(dest1,package1,"race_1") ;
    loc1->european =true ;
    priorityShipment1->shipSomething(dest1,package1,"race_2") ;





    delete package1 ;
    delete route1 ;
    delete priorityShipment1 ;
    return 0 ;
}