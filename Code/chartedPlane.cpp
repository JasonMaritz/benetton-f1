#include <exception>
#include <string>
using namespace std;

#include "chartedPlane.h"
#include "Location.h"
#include "TransportMode.h"

chartedPlane::chartedPlane(int aSpeed, Location aCurr):TransportMode(200,aCurr) {
}

time_t chartedPlane::eta(Location aDestination) {
	throw "Not yet implemented";
}

void chartedPlane::changeTransportMode() {
	throw "Not yet implemented";
}

