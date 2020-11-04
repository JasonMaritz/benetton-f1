//
// Created by chrissi-boi on 2020/11/04.
//

#include "RacingStrategyInterface.h"

#include <utility>
#include "../TyreFactories/TyreFactory.h"
#include "../TyreFactories/SoftTyreFactory.h"
#include "../TyreFactories/MediumTyreFactory.h"
#include "../TyreFactories/HardTyreFactory.h"
#include "StrategyName.h"

void RacingStrategyInterface::addSoftTyre()
{
    if(!this->hasName && tyreCount < 5)
    {
        this->tyreCount++;
        if(this->isFirst)
        {
            this->isFirst = false;
            this->racingStrategy = new SoftTyreFactory();
        }
        else
        {
            TyreFactory* softTyre = new SoftTyreFactory();
            this->racingStrategy->add(softTyre);
        }
    }
}

void RacingStrategyInterface::addMediumTyre()
{
    if(!this->hasName && tyreCount < 5)
    {
        this->tyreCount++;
        if(this->isFirst)
        {
            this->isFirst = false;
            this->racingStrategy = new MediumTyreFactory();
        }
        else
        {
            TyreFactory* mediumTyre = new MediumTyreFactory();
            this->racingStrategy->add(mediumTyre);
        }
    }
}

void RacingStrategyInterface::addHardTyre()
{
    if(!this->hasName && tyreCount < 5)
    {
        this->tyreCount++;
        if(this->isFirst)
        {
            this->isFirst = false;
            this->racingStrategy = new HardTyreFactory();
        }
        else
        {
            TyreFactory* hardTyre = new HardTyreFactory();
            Tyre* tyre = hardTyre->makeTyre();
            hardTyre->setTyre(tyre);
            this->racingStrategy->add(hardTyre);
        }
    }
}

string RacingStrategyInterface::getStrategy()
{
    return this->racingStrategy->getStrategy();
}

void RacingStrategyInterface::addName(string name)
{
    if(!this->hasName)
    {
        this->hasName = true;
        auto* strategyName = new StrategyName(std::move(name));
        this->racingStrategy->add(strategyName);
    }
}
