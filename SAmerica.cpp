#include "SAmerica.h"
#include"TrackContinent.h"
#include<iostream>
#include<string>
using namespace std;
/**
 * South American track constructor that initialises South American track properties
 */
SAmerica::SAmerica():TrackContinent() {
	// TODO - implement SAmerica::SAmerica

	cout << "South america Race Track" << endl;
			setLaps(5);
			setWear(9);

			setSpeed(4);

			setCorners(5);

			setLength(8);


			setFatigue(3);

			setCity("Rio");
}
