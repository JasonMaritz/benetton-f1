#include "NAmerica.h"
#include"TrackContinent.h"
#include<iostream>
#include<string>
using namespace std;
/**
 * North American track constructor that initialises North American track properties
 */
NAmerica::NAmerica():TrackContinent() {
	// TODO - implement NAmerica::NAmerica

	cout << "North America Race Track" << endl;
			setLaps(5);
			setWear(11);

			setSpeed(15);

			setCorners(4);

			setLength(8);


			setFatigue(3);

			setCity("New york");
}
