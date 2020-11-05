#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "ContainerRoute.h"
#include "ContainerSet.h"
#include "Destination.h"
#include "TransportMode.h"
#include "Location.h"
#include "LowPriority.h"
#include "HighPriority.h"
#include "routeIterator.h"

routeIterator* ContainerRoute::getRouteIterator() {
	throw "Not yet implemented";
}

void ContainerRoute::decideTransportMode() {
	throw "Not yet implemented";
}

void ContainerRoute::setContainers(ContainerSet* aContainers) {
	this->_containers = aContainers;
}

void ContainerRoute::setTransportMode(string aMode) {
	throw "Not yet implemented";
}

Location ContainerRoute::getCurrLocation() {
	return this->_currLocation;
}

void ContainerRoute::setCurrLocation(Location aCurrLocation) {
	this->_currLocation = aCurrLocation;
}

