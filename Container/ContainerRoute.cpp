#include "ContainerRoute.h"

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

void ContainerRoute::printRoute() {
	int nStops = stops.size();
	for (int i = 0; i < nStops - 1; i++) {
		cout << stops[i]->location.name << ", ";
	}
	cout << stops[nStops - 1]->location.name << endl;
}


TransportMode* ContainerRoute::getTransportMode() const{
	return transport ; 
}

void ContainerRoute::transportCargo(){
	if (transport != NULL){

		if (stops.size() > 0 ){ //High Priority
			// currLocation = getRouteIterator() ;
			for (auto dest = stops.begin() ; dest != stops.end(); dest++){
				transport->eta((*dest)->location) ;
				cout<<"Package to "<<(*dest)->location.name<<", will be arrive in: "<<transport->eta((*dest)->location)<<" seconds."<<endl ; //call to the make request
			}
		}
		else{
			cout<<"Package Destination was not set \n" ;
		}
	}
}


void ContainerRoute::setTransportMode(TransportMode* t){
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

ContainerSet* ContainerRoute::getContainers() const   {
	return containers ;
}