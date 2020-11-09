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
    Qualifying(F1Car** array);
    F1Car** StartQualifying();
private:
    void sortArray();
};


#endif //RACINGSTRATEGY_QUALIFYING_H
