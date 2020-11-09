#include "africa.h"
#include<iostream>

africa::africa() :TrackContinent()
{
	// TODO - implement africa::africa
	cout << "African Race Track" << endl;
	this->setLaps(6);
	this->setWear(5);
	this->setSpeed(4);
	this->setCorners(10);
	this->setLength(18);
	this->setFatigue(3);
	this->setCity("Pretoria");
}
