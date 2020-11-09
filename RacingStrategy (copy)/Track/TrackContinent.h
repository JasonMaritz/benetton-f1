#ifndef TRACKCONTINENT_H
#define TRACKCONTINENT_H
#include"Track.h"
#include<iostream>
#include<string>
using namespace std;

class TrackContinent :public Track {

private:
	Track* continent;
public:
	TrackContinent();
	virtual ~TrackContinent();

	virtual void add(Track* continent);
	  virtual int trackLaps();
		  virtual int trackWear();
		  virtual int trackSpeed();
		  virtual int trackCorner();
		  virtual int trackLength();
		  virtual int trackFatigues();
		  virtual string trackCity();

};

#endif
