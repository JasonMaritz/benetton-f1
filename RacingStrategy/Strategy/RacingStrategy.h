//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_RACINGSTRATEGY_H
#define RACINGSTRATEGY_RACINGSTRATEGY_H

#include <iostream>

using namespace std;

class RacingStrategy
{
private:
public:
    virtual void add(RacingStrategy* item) = 0;
    virtual string getStrategy() = 0;
};


#endif //RACINGSTRATEGY_RACINGSTRATEGY_H
