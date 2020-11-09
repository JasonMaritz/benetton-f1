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
    Race(F1Car** array, Track* newTrack, vector<Tyre*> tyres);
    F1Car** StartRace();
private:
    void sortArray();
};


#endif //RACINGSTRATEGY_RACE_H
