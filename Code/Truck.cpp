#include <exception>
#include <string>
using namespace std;

#include "Truck.h"
#include "Location.h"
#include "TransportMode.h"

time_t Truck::eta(Location aDestination) {
	throw "Not yet implemented";
}

Truck::Truck(int aSpeed, Location aCurr):TransportMode(180,aCurr) {
}

void Truck::changeTransportMode() {
	throw "Not yet implemented";
}

