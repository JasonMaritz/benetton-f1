#include "ContainerRoute.h"

ContainerRoute::ContainerRoute() {}

ContainerRoute::ContainerRoute(ContainerSet* c) {
	containers = c;
}

ContainerRoute::~ContainerRoute() {
	for (auto it = stops.begin(); it != stops.end(); it++) {
		delete (*it);
	}
	delete containers;
}

RouteIterator* ContainerRoute::getRouteIterator() {
	return new RouteIterator(&stops);
}

void ContainerRoute::setContainers(ContainerSet* c) {
	if (containers)
		delete containers;
	containers = c->clone();
}

void ContainerRoute::clearRoute() {
	for (auto it = stops.begin(); it != stops.end(); it++) {
		delete *it;
	}
	stops.clear();
}

void ContainerRoute::setStops(vector<Destination*>* s){
	clearRoute();

	for (auto it = s->begin(); it != s->end(); it++) {
		stops.push_back(new Destination(*it));
	}
}
