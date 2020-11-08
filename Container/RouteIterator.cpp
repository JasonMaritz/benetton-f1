#include "RouteIterator.h"

RouteIterator::RouteIterator(vector<Destination*>* a) {
	aggregate = a;
}

Destination* RouteIterator::first() {
	currIndex = 0;
	if (aggregate->size() > 0)
		return (*aggregate)[0];
	return 0;
}

Destination* RouteIterator::current() {
	if (aggregate->size() > currIndex)
		return (*aggregate)[currIndex];
	return 0;
}

Destination* RouteIterator::next() {
	currIndex++;
	return current();
}
