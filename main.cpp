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
#include "Container/PackedItem.h"


void testLowPriority2() {
	cout << "Routes for low priority containers (each line a new set of containers):\n";
	LowPriority lp;
	lp.destinationsFromtxt("Data/Destinations.txt");
	lp.setupRoutes();
	lp.printRoutes();

}

int main(){

    // testLowPriority2() ;

    PackedItem item1 ;
    item1.weight = 10 ;

    ContainerSet* package1 = new ContainerSet() ;
    package1->addItem("item1",&item1) ;

    ContainerRoute* route1 = new ContainerRoute(package1) ;

    HighPriority* priorityShipment1 = new HighPriority() ;
    Destination* dest1 = new Destination() ;
    Location* loc1 = new Location() ;
    loc1->name = "Hong Kong" ;
    loc1->european= false ;
    dest1->location = *loc1 ;

	// public: void shipSomething(Destination* aDest, ContainerSet* aContainers, string aName);
    priorityShipment1->shipSomething(dest1,package1,"race_1") ;
    loc1->european =true ;

    package1 = priorityShipment1->get("race_1");
    cout<<"Weight after shiping ?"<<package1->getWeight()<<endl ;
    dest1->location = *loc1 ;


    Location* loc2 = new  Location() ;
    loc2->european = false ;
    Destination * dest2 =new Destination() ;
    dest2->location = *loc2 ;
    priorityShipment1->shipSomething(dest2,package1,"race_2") ;


    // TransportMode* trans = route1->getTransportMode() ;
    // if (trans == NULL)
    // cout<<"NULL\n" ;   
    // else   trans->changeTransportMode() ;

    delete dest1 ; delete dest2 ;
    delete loc1 ; delete loc2 ;
    delete package1 ;
    delete route1 ;
    delete priorityShipment1 ;
    return 0 ;
}