#include "TrackContinent.h"

TrackContinent::TrackContinent() {
	// TODO - implement TrackContinent::TrackContinent
	continent=0;


}
TrackContinent::~TrackContinent() {
	//
	delete continent;
}

void TrackContinent::add(Track* cont) {
	// TODO - implement TrackContinent::add
	cout<<"adding to the track"<<endl;
	 if (continent == 0){
	        continent = cont;
	   } else {
	        continent->add(cont);
	   }
}

int TrackContinent::trackLaps(){
	 if (continent == 0) {

		 return getLaps();
	  } else {

		  return getLaps() + continent->trackLaps();
	  }
}
int TrackContinent::trackWear(){
	if (continent == 0) {

			 return getWear();
		  } else {

			  return getWear() + continent->trackLaps();
		  }
}
int TrackContinent::trackSpeed(){
	if (continent == 0) {

			 return getSpeed();
		  } else {

			  return getSpeed() + continent->trackSpeed();
		  }
}
int TrackContinent::trackCorner(){
	if (continent == 0) {

			 return getCorners();
		  } else {

			  return getCorners() + continent->trackCorner();
		  }
}
int TrackContinent::trackLength(){
	if (continent == 0) {

			 return getLength();
		  } else {

			  return getLength() + continent->trackLength();
		  }
 }
int TrackContinent::trackFatigues(){
	if (continent == 0) {

			 return getFatigue();
		  } else {

			  return getFatigue() + continent->trackFatigues();
		  }
}
string TrackContinent::trackCity(){
	if (continent == 0) {

			 return getCity();
		  } else {

			  continent->getCity()+continent-> trackCity();
		  }
}

