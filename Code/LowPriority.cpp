#include "LowPriority.h"

void LowPriority::setPrototype(ContainerSet* p) {
	if (prototypeContainer)
		delete prototypeContainer;
	prototypeContainer = p->clone();
}

void LowPriority::setDestinations(Destination* dests, int nDestinations){
	for (int i = 0; i < nDestinations; i++) {
		destinations.push_back(new Destination(&(dests[i])));
	}
}

void LowPriority::orderDestinations(vector<Destination*>& vec, bool byStart){
	vector<Destination*> tempVector;

	int size = vec.size();
	for (int i = 0; i < size; i++) {
		Destination* min = 0;
		int minIndex = -1;

		for (int j = 0; j < size; j++) {
			if (vec[j] == 0)
				continue;
		
			if (min == 0){
				min = vec[j];
				minIndex = j;
			}
			else {
				if (byStart) {
					if (min->startDate > vec[j]->startDate) {
						min = vec[j];
						minIndex = j;
					}
				}
				else {
					if (min->endDate > vec[j]->endDate) {
						min = vec[j];
						minIndex = j;
					}
				}
			}
		}
		vec[minIndex] = 0;
		tempVector.push_back(min);
	}

	for (int i = 0; i < size; i++) {
		vec[i] = tempVector[i];
	}
}

void LowPriority::setupRoutes() {
	orderDestinations(destinations, 1);
	
	//Split eu and non-eu
	vector<Destination*> euSegment;
	list<Destination*> nonEu; //Will be removed from randomly
	for (auto it = destinations.begin(); it != destinations.end(); it++) {
		if ((*it)->location.european) {
			euSegment.push_back(*it);
		}
		else {
			nonEu.push_back(*it);
		}
	}

	//Make Eu stand-in node (All EU races done with same container)
	Destination* eu = new Destination();
	eu->location.name = "eu";
	eu->startDate = euSegment.front()->startDate;
	eu->endDate = euSegment.back()->endDate;

	nonEu.push_back(eu);

	//Get 3 months in time_t format
	struct tm* t = new tm;
	t->tm_sec = 0;
	t->tm_min = 0;
	t->tm_hour = 0;
	t->tm_wday = 0;
	t->tm_yday = 0;
	t->tm_isdst = 0;
	t->tm_year = 0;
	t->tm_mday = 0;

	t->tm_mon = 3;

	time_t months3 = mktime(t);

	//construt paths to cover all of nonEu

	
	while (!nonEu.empty()) { //Each pass creates a new route
		time_t currTime = 0; //First destination is easy to reach, can just depart early
		vector<Destination*>* thisRoute = new vector<Destination*>;
		
		while (true) { //Each pass adds a destination
			bool addedDest = false;
			for (auto it = nonEu.begin(); it != nonEu.end();) {
				if ((*it)->startDate > currTime) {
					if ((*it)->location.name == "eu") {  //"eu" is a stand-in for all the europe-races
						for (auto it2 = euSegment.begin(); it2 != euSegment.end(); it++)
							thisRoute->push_back(*it);
					}
					else {
						thisRoute->push_back(*it);
					}

					currTime = (*it)->endDate; //Departure time
					currTime += months3; //3 months travel time added
					
					it = nonEu.erase(it);
					addedDest = true;
					break;
				}
				else {
					it++;
				}
			}
			if (!addedDest)
				break;
		}
		//Create ContainerRoute
		ContainerRoute* newRoute = new ContainerRoute(prototypeContainer);
		newRoute->setStops(thisRoute);
		routes.push_back(newRoute);

		delete thisRoute;
	}

	delete eu;
}