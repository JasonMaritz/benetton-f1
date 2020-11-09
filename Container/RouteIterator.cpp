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
	if (aggregate->size() > currIndex && currIndex >=0)
		return (*aggregate)[currIndex];
	return 0;
}

Destination* RouteIterator::next() {
	currIndex++;
	return current();
}

Destination* RouteIterator::prev() {
	currIndex--;
	return current();
}