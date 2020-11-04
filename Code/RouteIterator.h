#ifndef ROUTEITERATOR_H
#define ROUTEITERATOR_H

#include <vector>

#include "Destination.h"

using namespace std;

class RouteIterator{
private:
	vector<Destination*>* aggregate;
	int currIndex = 0;
public:
	RouteIterator(vector<Destination*>* a);
	Destination* first(); //currIndex = 0
	Destination* next(); //currIndex ++
	Destination* current();
};

#endif