#include "LowPriority.h"

#include <sstream>

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

	time_t months3 = 2592000 * 3; //3 months in seconds

	//construt paths to cover all of nonEu
	months3 = months3;
	
	while (!nonEu.empty()) { //Each pass creates a new route
		time_t currTime = 0; //First destination is easy to reach, can just depart early
		vector<Destination*>* thisRoute = new vector<Destination*>;
		
		while (true) { //Each pass adds a destination
			bool addedDest = false;
			for (auto it = nonEu.begin(); it != nonEu.end();) {
				if ((*it)->startDate > currTime) {
					if ((*it)->location.name == "eu") {  //"eu" is a stand-in for all the europe-races
						for (auto it2 = euSegment.begin(); it2 != euSegment.end(); it2++)
							thisRoute->push_back(*it2);
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

int LowPriority::getNumRoutes() {
	return routes.size();
}

ContainerRoute* LowPriority::getRoute(int index) {
	if (index < 0 || index >= getNumRoutes())
		return 0;
	return routes[index];
}

time_t LowPriority::timetFromStr(string date) {
	struct tm* t;
	t = new tm;
	t->tm_sec = 0;
	t->tm_min = 0;
	t->tm_hour = 0;
	t->tm_wday = 0;
	t->tm_yday = 0;
	t->tm_isdst = 0;

	int y = atoi(date.substr(6, 9).c_str());
	t->tm_year = y - 1900;
	y = atoi(date.substr(3, 5).c_str());
	t->tm_mon = y;
	y = atoi(date.substr(0, 2).c_str());
	t->tm_mday = y;

	return mktime(t);
}

void LowPriority::destinationsFromtxt()
{
    stringstream  ss1(this->getDestinations());
	string line;
	while (getline(ss1, line, '\n'))
	{
		string name;
		string startDate;
		string endDate;
		string eu;

		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, startDate, ',');
		getline(ss, endDate, ',');
		getline(ss, eu);

		auto* d = new Destination;
		d->startDate = timetFromStr(startDate);
		d->endDate = timetFromStr(endDate);
		d->location.name = name;
		d->location.european = (eu == "1" ? 1 : 0);
		destinations.push_back(d);
	}
}

void LowPriority::printRoutes()
{
	int count = 1;
    for (auto it = routes.begin(); it != routes.end(); it++)
	{
		cout << "Container Set " << count << ":  ";
	    (*it)->printRoute();
	    count++;
	}
    cout << endl << endl;
}

string LowPriority::getDestinations()
{
    string filename =
            "Austria,05-07-2020,07-07-2020,1\n"
            "Styria,12-07-2020,14-07-2020,0\n"
            "Hungary,19-07-2020,22-07-2020,1\n"
            "Great Britain,02-08-2020,05-08-2020,1\n"
            "Anniversary,09-08-2020,11-08-2020,0\n"
            "Spain,16-08-2020,18-08-2020,1\n"
            "Belgium,30-08-2020,02-09-2020,1\n"
            "Italy,06-09-2020,08-09-2020,1\n"
            "Tuscany,13-09-2020,15-09-2020,0\n"
            "Russia,27-09-2020,29-09-2020,0\n"
            "Eifel,11-10-2020,13-10-2020,1\n"
            "Portugal,25-10-2020,27-10-2020,1\n"
            "Emilia Romagna,01-11-2020,03-11-2020,0\n"
            "Turkey,15-11-2020,17-11-2020,1\n"
            "Bahrain,29-11-2020,01-12-2020,0\n"
            "Sakhir,06-12-2020,08-12-2020,0\n"
            "Abu Dhabi,13-12-2020,15-12-2020,0";
    return filename;
}
