#include "Asia.h"
#include"TrackContinent.h"
#include<iostream>
#include<string>
using namespace std;

/**
 * Asian track constructor that initialises Asian track properties
 */
Asia::Asia():TrackContinent() {
	// TODO - implement Asia::Asia

	cout << "Asian Race Track" << endl;
		setLaps(3);
		setWear(4);

		setSpeed(7);

		setCorners(5);

		setLength(8);


		setFatigue(4);

		setCity("Tokyo");
}
