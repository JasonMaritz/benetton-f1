//
// Created by chrissi-boi on 2020/11/09.
//

#ifndef RACINGSTRATEGY_RACE_H
#define RACINGSTRATEGY_RACE_H


#include "../F1Car/include/F1Car.h"
#include "../Track/Track.h"
#include "../Tyres/Tyre.h"
#include <cstdlib>
#include <ctime>

class Race
{
private:
    F1Car* carArray[20];
    Track* track;
    vector<Tyre*> ourTyres;
public:
    ///Constructor that create an Race object for the RaceWeekendInterface to use to run a race
    ///@param array An array of F1Car
    ///@param newTrack A Track object for the race to use.
    ///@param tyres A vector of type Tyre that holds the tyres for the race
    Race(F1Car** array, Track* newTrack, vector<Tyre*> tyres);
    ///The function that the RaceWeekendInterface object uses to start a race.
    ///@returns A pointer to the F1Car array
    F1Car** StartRace();
private:
    ///A function to sort the F1Car array based on race time.
    void sortArray();
};


#endif //RACINGSTRATEGY_RACE_H
