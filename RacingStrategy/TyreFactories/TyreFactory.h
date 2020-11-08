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
    string getStrategy() override;
    void add(RacingStrategy *item) override;
    virtual Tyre* makeTyre() = 0;
    void setTyre(Tyre* newTyre);
};


#endif //RACINGSTRATEGY_TYREFACTORY_H
