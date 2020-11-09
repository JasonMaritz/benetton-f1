//
// Created by chrissi-boi on 2020/11/09.
//

#ifndef RACINGSTRATEGY_QUALIFYING_H
#define RACINGSTRATEGY_QUALIFYING_H


#include "../F1Car/include/F1Car.h"

class Qualifying
{
private:
    F1Car* carArray[20];
public:
    ///Constructor that create an Qualifying object for the RaceWeekendInterface to use to run a Qualifying session
    ///@param array An array of type F1Car
    Qualifying(F1Car** array);
    ///The function that the RaceWeekendInterface object uses to start a Qualifying session.
    ///@returns A pointer to the F1Car array
    F1Car** StartQualifying();
private:
    ///A function to sort the F1Car array based on qualifying time.
    void sortArray();
};


#endif //RACINGSTRATEGY_QUALIFYING_H
