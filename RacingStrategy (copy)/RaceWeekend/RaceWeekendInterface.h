//
// Created by chrissi-boi on 2020/11/09.
//

#ifndef RACINGSTRATEGY_RACEWEEKENDINTERFACE_H
#define RACINGSTRATEGY_RACEWEEKENDINTERFACE_H

#include <sstream>
#include "../Strategy/RacingStrategy.h"
#include "../Track/Track.h"
#include "../F1Car/include/F1Car.h"
#include "../Tyres/Tyre.h"
#include "../Strategy/RacingStrategyInterface.h"
#include "../R&D/include/Engineering.h"
#include "../F1Car/include/RaceBuilderDir.h"

class RaceWeekendInterface
{
private:
    RacingStrategyInterface* rci;
    RacingStrategy* racingStrategy;
    Track* track;
    F1Car* car;
    F1Car* carArray[20];
    vector<Part*> ourParts;
    vector<Tyre*> ourTyres;
    Engineering* engineering;
    RaceBuilderDir* CarBuilder;
public:
    RaceWeekendInterface(string ContainerName, Track* newTrack);
    void StartRaceWeekend();
private:
    void breakContainerIntoParts(ContainerSet* container);
    void breakContainerIntoTyres(ContainerSet* container);
    void buildCar();
    bool isInOurParts(string partName);
};


#endif //RACINGSTRATEGY_RACEWEEKENDINTERFACE_H
