#include "RaceCategory.h"



RaceCategory::RaceCategory() {
	// TODO - implement RaceCategory::RaceCategory
}

void RaceCategory::add(Track* track){

}
/**
 * this function returns number of laps
 * @return laps, the attribute being returned
 */
int RaceCategory::trackLaps(){


		 return getLaps();

}
/**
 * this function returns wear factor
 * @return wear, the attribute being returned
 */
int RaceCategory::trackWear(){

			 return getWear();

}
/**
 * this function returns track speed
 * @return speed, the attribute being returned
 */
int RaceCategory::trackSpeed(){

			 return getSpeed();

}
/**
 * this function returns number of Corners
 * @return corner, the attribute being returned
 */
int RaceCategory::trackCorner(){

			 return getCorners();

}
/**
 * this function returns track length
 * @return length, the attribute being returned
 */
int RaceCategory::trackLength(){

			 return getLength();

 }
/**
 * this function returns fatigues
 * @return fatigue, the attribute being returned
 */
int RaceCategory::trackFatigues(){

			 return getFatigue();

}
/**
 * this function returns the host city
 * @return city, the attribute being returned
 */
string RaceCategory::trackCity(){

			 return getCity();

}


