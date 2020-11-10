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
    F1Car* carArray[20];
    vector<Part*> ourParts;
    vector<Tyre*> ourTyres;
    Engineering* engineering;
    RaceBuilderDir* CarBuilder;
    string DriverNames [20];
public:
    ///Constructor to create a Object used by main to handle a race weekend.
    ///@param ContainerName A string holding the name of the container set.
    ///@param newTrack A tack object holding the track used by the race.
    RaceWeekendInterface(string ContainerName, Track* newTrack);
    ///Function to start the the race weekend starting the qualifying and the race.
    void StartRaceWeekend();
private:
    ///Function to open the ContainerSet object and get all the Part objects out of it and store them.
    ///@param container A ContainerSet object holding all the PackItems needed for a race.
    void breakContainerIntoParts(ContainerSet* container);
    ///Function to open the ContainerSet object and get all the Tyre objects out of it and store them.
    ///@param container A ContainerSet object holding all the PackItems needed for a race.
    void breakContainerIntoTyres(ContainerSet* container);
    ///Functin to build the F1Car object using the parts from the ContainerSet object
    void buildCar();
    ///A search function to see if a specific part is in our list of Parts.
    ///@param partName The string value of the type of a specific Part ofject
    ///@returns A bool value, true if the part is in the list and false if it is not.
    bool isInOurParts(string partName);
    ///A function to add names to the list of drivers.
    void addDrivers();
};


#endif //RACINGSTRATEGY_RACEWEEKENDINTERFACE_H
