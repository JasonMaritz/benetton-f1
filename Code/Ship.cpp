#include <exception>
#include <string>
using namespace std;

#include "Ship.h"
#include "Location.h"
#include "TransportMode.h"

Ship::Ship(int aWindSpeed, Location aCurr):TransportMode(65,aCurr) {
}

time_t Ship::eta(Location aDestination) {
	throw "Not yet implemented";
}

void Ship::changeTransportMode() {
	throw "Not yet implemented";
}

