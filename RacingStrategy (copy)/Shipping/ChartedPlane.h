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
		ChartedPlane(Location aCurr, ContainerRoute* r,int a = 200);

		virtual time_t eta(Location aDestination);

		virtual void changeTransportMode(bool );
};

#endif
