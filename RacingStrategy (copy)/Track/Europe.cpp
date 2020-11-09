#include "Europe.h"
#include"TrackContinent.h"
#include<iostream>
#include<string>
using namespace std;
/**
 * Europe track constructor that initialises Europe track properties
 */
Europe::Europe() {
	// TODO - implement Europe::Europe

	cout << "Europe Race Track" << endl;
			setLaps(5);
			setWear(2);

			setSpeed(4);

			setCorners(10);

			setLength(8);


			setFatigue(3);

			setCity("paris");
}
