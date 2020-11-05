#include <exception>
#include <string>
using namespace std;

#include "TransportMode.h"
#include "ContainerRoute.h"
#include "Location.h"

time_t TransportMode::eta(Location aDestination) {
	throw "Not yet implemented";
	//returns time_t
	//diferent specializations use different calculations
}

TransportMode::TransportMode(int aSpeed, Location aCurr) {
	_speed = aSpeed ;
	_destination = aCurr ;
}

void TransportMode::changeTransportMode() {
	throw "Not yet implemented";
	//method that will change the tranport for the context
}

bool TransportMode::getOnRoute() {
	return this->_onRoute;
}

void TransportMode::setOnRoute(bool aOnRoute) {
	this->_onRoute = aOnRoute;
}

ContainerRoute* TransportMode::getRoute() {
	return this->_route;
}

void TransportMode::setRoute(ContainerRoute* aRoute) {
	this->_route = aRoute;
}

Location TransportMode::getDestination() {
	return this->_destination;
}

void TransportMode::setDestination(Location aDestination) {
	this->_destination = aDestination;
}

