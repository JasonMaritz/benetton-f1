#include <exception>
#include <string>
using namespace std;

#ifndef __Ship_h__
#define __Ship_h__

#include "Location.h"
#include "TransportMode.h"

class Location;
// class TransportMode;
class Ship;

class Ship: public TransportMode
{

	public: Ship(int aWindSpeed, Location aCurr);

	public: time_t eta(Location aDestination);

	public: void changeTransportMode();
};

#endif
