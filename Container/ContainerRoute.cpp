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

void ContainerRoute::decideTransportMode(){ //used by low
	
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
		while (dest != NULL ){
			cout<<"Package will be arrive in: "<<transport->eta(dest->location)<<" seconds."<<endl ; //call to the make request
			dest = currLocation->next() ;
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
