#include "Track.h"
#include"../Simulation/Result.h"
using namespace std;
#include <iostream>
#include <string>

/**
 * This is the constructor which initiases defaults values to the attribute
 */
Track::Track() {
	// TODO - implement Track::Track

	 city="";
	laps=0;
	speed=0;
	corners=0;
	length=0;
	fatigue=0;
	wear=0;
	//result=0;
}

/**
 * This function returns wear factor of the track
 * @return wear, the attribute being returned
 */
int Track::getWear() {
	return this->wear;
}

/**
 *This function takes in wear as a parameter and initialse it to the wear attribute
 * @param wear, the attribute being returned
 */
void Track::setWear(int wear) {
	this->wear = wear;
}

/**
 * This function returns number of laps of the track
 * @return laps, the attribute being returned
 */
int Track::getLaps() {
	return this->laps;
}

/**
 * This function takes in laps as a parameter and initialse it to the laps attribute
 * @param laps,the parameter being pass in
 */
void Track::setLaps(int laps) {
	this->laps = laps;
}

/**
 * This function returns the speed of the track
 * @return speed, the attribute being returned
 */
int Track::getSpeed() {
	return this->speed;
}

/**
 * This function takes in speed as a parameter and initialse it to the speed attribute
 * @param speed,the parameter being pass in
 */
void Track::setSpeed(int speed) {
	this->speed = speed;
}

/**
 * This function returns number of corners in the track
 * @return corners, the attribute being returned
 */
int Track::getCorners() {
	return this->corners;
}

/**
 * This function takes in corners as a parameter and initialse it to the corners attribute
 * @param corners,the parameter being pass in
 */

void Track::setCorners(int corners) {
	this->corners = corners;
}

/**
 * This function returns the length of the track
 * @return length,the parameter being pass in
 */
int Track::getLength() {
	return this->length;
}
/**
 * This function takes in length as a parameter and initialse it to the length attribute
 * @param length,the parameter being pass in
 */
void Track::setLength(int length) {
	this->length = length;
}

/**
 * This function returns fatigue of the track
 * @return fatigue
 */
int Track::getFatigue() {

	return fatigue;
}

/**
 * This function takes in fatigue as a parameter and initialse it to the fatigue attribute
 * @param fatigue,the parameter being pass in
 */

void Track::setFatigue(int fatigue) {
	this->fatigue = fatigue;
}

/**
 * This function returns the host city of the track
 * @return city, the attribute being returned
 */
string Track::getCity() {
	return this->city;
}
/**
 * This function takes in city as a parameter and initialse it to the city attribute
 * @param city,the parameter being pass in
 */
void Track::setCity(string city) {
	this->city = city;
}
/**
 * This function takes in results as a parameter and initialse it to the result object attribute
 * @param res,the parameter being pass in
 */
void Track::setResult(Result* res){

	this->result=res;
}


/**
 * this function generate a report of properties of the specific track race it is working with then pass
 *  the report as a string to results object
 */
void Track::generateReport() {

	string report="Simulation used track with following properties:\n";
	report+= "Host City: "+ trackCity() +"\n";
	report+= "Number of Laps: "+ to_string(trackLaps()) +"\n";
	report+= "Wear Factor: "+ to_string(trackWear()) +"\n";
	report+= "Speed: "+ to_string(trackSpeed()) +"\n";
	report+= "Number of corners: "+ to_string(trackCorner()) +"\n";
	report+= "Fatigue: "+ to_string(trackFatigues()) +"\n";
	result->setTrackReport(report);

}



