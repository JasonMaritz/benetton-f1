//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_STRATEGYNAME_H
#define RACINGSTRATEGY_STRATEGYNAME_H


#include "RacingStrategy.h"

class StrategyName : public RacingStrategy
{
private:
    string name;

public:
    StrategyName(string name);
    void add(RacingStrategy* item) override;
    string getStrategy() override;
};


#endif //RACINGSTRATEGY_STRATEGYNAME_H
