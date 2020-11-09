#include <exception>
#include <string>
using namespace std;

#ifndef __ChartedPlane_h__
#define __ChartedPlane_h__

#include "../Container/Location.h"
#include "TransportMode.h"
#include "Truck.h"

class Location;
// class TransportMode;
class chartedPlane;

class ChartedPlane: public TransportMode
{

	public: 
		/// @param aDest specifies the destination for the shipment
		/// @param r pointer to a ContainerRoute 
		/// @param a speed of the tranportMode
		ChartedPlane(Location aCurr, ContainerRoute* r,int a = 200);
		
		/// @param aDestination the destination for the sipment
		virtual time_t eta(Location& aDestination);

		/// @todo changes route transportMode for offloading
		virtual void changeTransportMode(bool );
};

#endif
