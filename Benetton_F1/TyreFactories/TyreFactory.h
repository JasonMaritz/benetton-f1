//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_TYREFACTORY_H
#define RACINGSTRATEGY_TYREFACTORY_H

#include "../Strategy/RacingStrategy.h"
#include "../Tyres/Tyre.h"

class TyreFactory : public RacingStrategy
{
private:
    Tyre* tyre = nullptr;
    RacingStrategy* component = nullptr;

public:
    ///Function used to get a representation of the current race strategy.
    /// @returns A string holding the current tyre and parts strategy along with a name if it has one.
    string getStrategy() override;
    ///Function that adds an object to the RacingStrategy linked list.
    /// @param item A RacingStrategy Object is passed to be added to the linked list of RacingStrategy objects.
    void add(RacingStrategy *item) override;
    /// @returns The appropriate Tyre object.
    virtual Tyre* makeTyre() = 0;
    /// @param newTyre The new tyre object the current tyre member variable must point to.
    void setTyre(Tyre* newTyre);
};


#endif //RACINGSTRATEGY_TYREFACTORY_H
