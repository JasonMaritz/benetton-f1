#include <exception>
#include <string>
using namespace std;

#ifndef __Ship_h__
#define __Ship_h__

#include "../Container/Location.h"
#include "TransportMode.h"
#include "Truck.h"

class Location;
// class TransportMode;
class Ship;

class Ship: public TransportMode
{

	public: Ship( Location aCurr, ContainerRoute* r,int a = 65);

	public: time_t eta(Location aDestination);

	public: void changeTransportMode(bool );
};

#endif
