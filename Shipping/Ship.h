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
	/// @param aDest specifies the destination for the shipment
	/// @param r pointer to a ContainerRoute 
	/// @param a speed of the tranportMode
	public: Ship( Location aDest, ContainerRoute* r,int a = 65);

	/// @param aDestination the destination for shipment
	public: time_t eta(Location& aDestination);

	/// @todo changes route transportMode for offloading
	public: void changeTransportMode(bool );
};

#endif
