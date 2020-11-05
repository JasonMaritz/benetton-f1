#include <exception>
#include <string>
using namespace std;

#ifndef __chartedPlane_h__
#define __chartedPlane_h__

#include "Location.h"
#include "TransportMode.h"

class Location;
// class TransportMode;
class chartedPlane;

class chartedPlane: public TransportMode
{

	public: chartedPlane(int aSpeed, Location aCurr);

	public: time_t eta(Location aDestination);

	public: void changeTransportMode();
};

#endif
