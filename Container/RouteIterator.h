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
	///@param Pointer to vector this should iterate over
	RouteIterator(vector<Destination*>* a);
	///@returns corresponding Destination*
	Destination* first(); //currIndex = 0
	///@returns corresponding Destination*
	Destination* prev(); //currIndex--
	///@returns corresponding Destination*
	Destination* next(); //currIndex++
	///@returns corresponding Destination*
	Destination* current();
};

#endif