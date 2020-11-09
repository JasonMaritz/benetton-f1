#include "ContainerRoute.h"

#include "../Shipping/TransportMode.h"
#include "../Shipping/Ship.h"
#include "../Shipping/Truck.h"
#include "../Shipping/ChartedPlane.h"

#include <iostream>

using namespace std;

ContainerRoute::ContainerRoute() {}

ContainerRoute::ContainerRoute(ContainerSet* c) {
	containers = c;
}

ContainerRoute::~ContainerRoute() {
	for (auto it = stops.begin(); it != stops.end(); it++) {
		delete (*it);
	}
	delete containers;

	if (currLocation != NULL){
	delete currLocation ;
	}
}

RouteIterator* ContainerRoute::getRouteIterator() {
	return new RouteIterator(&stops);
}

void ContainerRoute::setContainers(ContainerSet* c) {
	if (containers)
		delete containers;
	containers = c->clone();
}

ContainerSet* ContainerRoute::getContainers() {
	return containers;
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

void ContainerRoute::decideTransportMode(){ //used by LowPriority
	if (!currLocation) {
		currLocation = getRouteIterator();
		currLocation->first();
	}
	Destination* a = currLocation->current();//Destination
	Destination* b = currLocation->prev();//Origin
	currLocation->next();
	if (!a) {
		return; //At end of route
	}
	if (!b) {
		setTransportMode("ship");
	}
	if (b->location.european && a->location.european)
		setTransportMode("truck");
	else
		setTransportMode("ship");

}

TransportMode* ContainerRoute::getTransportMode() const{
	return transport ;
}

void ContainerRoute::transportCargo(){
	if (transport != NULL){

		if (currLocation == NULL){ //High Priority
			currLocation = getRouteIterator() ;
		}
		Destination* dest = currLocation->current() ;
		if (dest != NULL ){
			transport->eta(dest->location) ; //call to the make request
		}
		else{
			// mktimplease set a dest ?
		}
	}
}

void ContainerRoute::setTransportMode(string mode) {
	//"plane", "truck", "ship" are the accepted parameters
	TransportMode* newMode = 0;
	if (mode == "plane") {
		newMode = new ChartedPlane(currLocation->current()->location, this);
	}
	else if (mode == "truck") {
		newMode = new ChartedPlane(currLocation->current()->location, this);
	}
	else if (mode == "ship") {
		newMode = new ChartedPlane(currLocation->current()->location, this);
	}
	else return;
	setTransportMode(newMode);
}


void ContainerRoute::setTransportMode(TransportMode* t){
	if (transport)
		delete transport;
	transport =t ;
}

Location* ContainerRoute::getCurrLocation(){
	if (currLocation == NULL){
		return NULL ;
	}
	else{
		return &currLocation->current()->location ;
	}
}

void ContainerRoute::printRoute() {
	int nStops = stops.size();
	for (int i = 0; i < nStops - 1; i++) {
		cout << stops[i]->location.name << ", ";
	}
	cout << stops[nStops - 1]->location.name << endl;
}
