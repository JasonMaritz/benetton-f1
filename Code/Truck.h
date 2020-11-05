#include <exception>
#include <string>
using namespace std;

#ifndef __Truck_h__
#define __Truck_h__

#include "Location.h"
#include "TransportMode.h"

class Location;
// class TransportMode;
class Truck;

class Truck: public TransportMode
{

	public: time_t eta(Location aDestination);

	public: Truck(int aSpeed, Location aCurr);

	public: void changeTransportMode();
};

#endif
