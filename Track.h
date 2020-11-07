#ifndef TRACK_H
#define TRACK_H

class Track {

private:
	String city;
	int laps;
	int speed;
	int corners;
	int length;
	int fatigue;

public:
	virtual void add(Track* track) = 0;

	Track();

	int getLaps();

	void setLaps(int laps);

	int getSpeed();

	void setSpeed(int speed);

	int getCorners();

	void setCorners(int corners);

	int getLength();

	void setLength(int length);

	string getFatigue();

	void setFatigue(int fatigue);

	String getCity();

	void setCity(String city);
};

#endif
