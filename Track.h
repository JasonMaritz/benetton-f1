#ifndef TRACK_H
#define TRACK_H
#include<iostream>
#include<string>
using namespace std;

class Track {

private:
	string city;
	int laps;
	int wear;
	int speed;
	int corners;
	int length;
	int fatigue;

protected:
	Result* result;

public:
	virtual void add(Track* track) = 0;
	  virtual int trackLaps() = 0;
	  virtual int trackWear() = 0;
	  virtual int trackSpeed() = 0;
	  virtual int trackCorner() = 0;
	  virtual int trackLength() = 0;
	  virtual int trackFatigues() = 0;
	  virtual string trackCity() = 0;


	Track();

	int getLaps();
	int getWear();
	void setWear(int wear);

	void setLaps(int laps);

	int getSpeed();

	void setSpeed(int speed);

	int getCorners();

	void setCorners(int corners);

	int getLength();

	void setLength(int length);

	int getFatigue();

	void setFatigue(int fatigue);

	string getCity();

	void setCity(string city);
	void setResult(Result*);
	void generateReport();



};

#endif
