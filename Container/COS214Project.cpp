#include <iostream>
#include <ctime>
#include <fstream>

#include "LowPriority.h"

using namespace std;

void testLowPriority();

int main(){
	testLowPriority();

}

void testLowPriority() {
	cout << "Routes for low priority containers (each line a new set of containers):\n";
	LowPriority lp;
	lp.destinationsFromtxt("Data/Destinations.txt");
	lp.setupRoutes();
	lp.printRoutes();

}
