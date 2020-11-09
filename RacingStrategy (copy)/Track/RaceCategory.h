#ifndef RACECATEGORY_H
#define RACECATEGORY_H
#include"Track.h"
#include<iostream>
#include<string>
using namespace std;

class RaceCategory : public Track {


public:


	RaceCategory();

	virtual void add(Track* track);
	 virtual int trackLaps();
			  virtual int trackWear();
			  virtual int trackSpeed();
			  virtual int trackCorner();
			  virtual int trackLength();
			  virtual int trackFatigues();
			  virtual string trackCity();
};

#endif
