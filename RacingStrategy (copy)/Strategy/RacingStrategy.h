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
    /// Pure virtual function used to add a RacingStrategy object to the RacingStrategy linked list.
    /// @param item A RacingStrategy object that is to be added to the RacingStrategy linked list.
    virtual void add(RacingStrategy* item) = 0;
    ///Function used to get a representation of the current race strategy.
    /// @returns A string holding the current tyre and parts strategy along with a name if it has one.
    virtual string getStrategy() = 0;
};


#endif //RACINGSTRATEGY_RACINGSTRATEGY_H
