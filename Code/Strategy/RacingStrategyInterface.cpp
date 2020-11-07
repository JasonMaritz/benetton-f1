//
// Created by chrissi-boi on 2020/11/04.
//

#include "RacingStrategyInterface.h"

#include <utility>
#include <sstream>
#include "../TyreFactories/TyreFactory.h"
#include "../TyreFactories/SoftTyreFactory.h"
#include "../TyreFactories/MediumTyreFactory.h"
#include "../TyreFactories/HardTyreFactory.h"
#include "StrategyName.h"
#include "../Tyres/SoftTyre.h"
#include "../Container/ContainerSet.h"
#include "../Tyres/MediumTyre.h"
#include "../Tyres/HardTyre.h"

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

ContainerSet* RacingStrategyInterface::buildAndGetContainerSet()
{
    auto* containerSet = new ContainerSet();
    int tyreCounter = 1;
    int partCounter = 1;

    string strategy = this->racingStrategy->getStrategy();
    stringstream ss(strategy);
    string to;
    if(!strategy.empty())
    {
        while(getline(ss, to, '\n'))
        {
            string type = to.substr(0,1);
            if(type == "T")
            {
                Tyre* tyre;
                string tyreType = to.substr(3);
                if(tyreType == "Soft")
                {
                    tyre = new SoftTyre();
                    tyre->make();
                    string tyreName = "Tyre_" + to_string(tyreCounter);
                    containerSet->addItem(tyreName, tyre);
                    tyreCounter++;
                }
                else if(tyreType == "Medium")
                {
                    tyre = new MediumTyre();
                    tyre->make();
                    string tyreName = "Tyre_" + to_string(tyreCounter);
                    containerSet->addItem(tyreName, tyre);
                    tyreCounter++;
                }
                else if(tyreType == "Hard")
                {
                    tyre = new HardTyre();
                    tyre->make();
                    string tyreName = "Tyre_" + to_string(tyreCounter);
                    containerSet->addItem(tyreName, tyre);
                    tyreCounter++;
                }
            }
            else if(type == "P")
            {

            }
        }
    }

    return containerSet;
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

string RacingStrategyInterface::getStrategy()
{
    return this->racingStrategy->getStrategy();
}
