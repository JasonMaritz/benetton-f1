//
// Created by chrissi-boi on 2020/11/04.
//

#ifndef RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
#define RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H


#include "RacingStrategy.h"

class RacingStrategyInterface
{
private:
    RacingStrategy* racingStrategy = nullptr;
    bool hasName = false;
    bool isFirst = true;
    int tyreCount = 0;

public:
    void addSoftTyre();
    void addMediumTyre();
    void addHardTyre();
    void addName(string name);
    string getStrategy();
};


#endif //RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
