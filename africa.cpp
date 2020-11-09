#include "africa.h"
#include<iostream>
#include<string>
#include"TrackContinent.h"

using namespace std;


/**
 * African track constructor that initialises African track properties
 */
africa::africa() :TrackContinent(){
	// TODO - implement africa::africa


	cout << "African Race Track" << endl;
	setLaps(6);
	setWear(5);

	setSpeed(4);

	setCorners(10);

	setLength(18);


	setFatigue(3);

	setCity("Pretoria");

}
