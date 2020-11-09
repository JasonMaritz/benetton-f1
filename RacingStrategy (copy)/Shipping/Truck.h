#include <exception>
#include <string>
using namespace std;

#ifndef __Truck_h__
#define __Truck_h__

#include "../Container/Location.h"
#include "TransportMode.h"
#include "ChartedPlane.h"
#include "Ship.h"

class Location;
// class TransportMode;
class Truck;

class Truck: public TransportMode
{

	public:
		virtual time_t eta(Location aDestination);

		Truck(Location aCurr, ContainerRoute* r,int a = 180);

		virtual void changeTransportMode(bool a) ;
};

#endif
