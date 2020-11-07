#include "Track.h"

Track::Track() {
	// TODO - implement Track::Track

	 city="";
	laps=0;
	speed=0;
	corners=0;
	length=0;
	fatigue=0;
	wear=0;
}
int Track::getWear() {
	return this->wear;
}
void Track::setWear(int w) {
	this->wear = w;
}

int Track::getLaps() {
	return this->laps;
}

void Track::setLaps(int laps) {
	this->laps = laps;
}

int Track::getSpeed() {
	return this->speed;
}

void Track::setSpeed(int speed) {
	this->speed = speed;
}

int Track::getCorners() {
	return this->corners;
}

void Track::setCorners(int corners) {
	this->corners = corners;
}

int Track::getLength() {
	return this->length;
}

void Track::setLength(int length) {
	this->length = length;
}

int Track::getFatigue() {
	// TODO - implement Track::getFatigue
	throw "Not yet implemented";
}

void Track::setFatigue(int fatigue) {
	this->fatigue = fatigue;
}

string Track::getCity() {
	return this->city;
}

void Track::setCity(string city) {
	this->city = city;
}
