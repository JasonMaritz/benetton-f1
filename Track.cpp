#include "Track.h"

Track::Track() {
	// TODO - implement Track::Track
	throw "Not yet implemented";
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

string Track::getFatigue() {
	// TODO - implement Track::getFatigue
	throw "Not yet implemented";
}

void Track::setFatigue(int fatigue) {
	this->fatigue = fatigue;
}

String Track::getCity() {
	return this->city;
}

void Track::setCity(String city) {
	this->city = city;
}
