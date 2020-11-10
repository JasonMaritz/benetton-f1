#include "TrackContinent.h"

/**
 * This function initialises the default Value to continent attribute
 */
TrackContinent::TrackContinent() {
	// TODO - implement TrackContinent::TrackContinent
	continent=0;


}
/**
 * This function deaalocates destroys the component object
 */
TrackContinent::~TrackContinent() {
	//
	delete continent;
}
/**
 * This function takes in continent as a parameter and adds it to the Track, it first checks if
 *  continent is empty, if it is then continent gets initialised
 * @param cont
 */
void TrackContinent::add(Track* cont) {
	// TODO - implement TrackContinent::add
	cout<<"adding to the track"<<endl;
	 if (continent == 0){
	        continent = cont;
	   } else {
	        continent->add(cont);
	   }
}

/**
 * This function returns Laps if continent has been initialised and returns the default
 *  value of laps if it has not yet been initialised, in this case if it's equal to 0
 * @return Laps
 */
int TrackContinent::trackLaps(){
	 if (continent == 0) {

		 return getLaps();
	  } else {

		  return getLaps() + continent->trackLaps();
	  }
}

/**
 * This function returns wear if continent has been initialised and returns the default
 *  value of wear if it has not yet been initialised, in this case if it's equal to 0
 * @return wear
 */
int TrackContinent::trackWear(){
	if (continent == 0) {

			 return getWear();
		  } else {

			  return getWear() + continent->trackWear();
		  }
}

/**
 * This function returns speed if continent has been initialised and returns the default
 *  value of speed if it has not yet been initialised, in this case if it's equal to 0
 * @return speed
 */
int TrackContinent::trackSpeed(){
	if (continent == 0) {

			 return getSpeed();
		  } else {

			  return getSpeed() + continent->trackSpeed();
		  }
}
/**
 * This function returns corner if continent has been initialised and returns the default
 *  value of corner if it has not yet been initialised, in this case if it's equal to 0
 * @return corner
 */
int TrackContinent::trackCorner(){
	if (continent == 0) {

			 return getCorners();
		  } else {

			  return getCorners() + continent->trackCorner();
		  }
}

/**
 * This function returns length if continent has been initialised and returns the default
 *  value of length if it has not yet been initialised, in this case if it's equal to 0
 * @return length
 */
int TrackContinent::trackLength(){
	if (continent == 0) {

			 return getLength();
		  } else {

			  return getLength() + continent->trackLength();
		  }
 }
/**
 * This function returns fatigue if continent has been initialised and returns the default
 *  value of fatigue if it has not yet been initialised, in this case if it's equal to 0
 * @return fatigue
 */
int TrackContinent::trackFatigues(){
	if (continent == 0) {

			 return getFatigue();
		  } else {

			  return getFatigue() + continent->trackFatigues();
		  }
}
/**
 * This function returns city if continent has been initialised and returns the default
 *  value of city if it has not yet been initialised, in this case if it's equal to 0
 * @return city
 */
string TrackContinent::trackCity(){
	if (continent == 0) {

			 return getCity();
		  } else {

			 return continent->getCity()+continent-> trackCity();
		  }
}

