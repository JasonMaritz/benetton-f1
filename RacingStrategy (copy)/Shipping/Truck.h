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
		/// @param aDestination the destination for shipment
		virtual time_t eta(Location& aDestination);

		/// @todo changes route transportMode for offloading
		Truck(Location aCurr, ContainerRoute* r,int a = 180);
			
		/// @param aDest specifies the destination for the shipment
		/// @param r pointer to a ContainerRoute 
		/// @param a speed of the tranportMode
		virtual void changeTransportMode(bool a) ;
};

#endif
