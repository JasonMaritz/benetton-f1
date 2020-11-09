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
#include "../Tyres/MediumTyre.h"
#include "../Tyres/HardTyre.h"

RacingStrategyInterface::RacingStrategyInterface()
{
    this->engineering = Engineering::getInstance();
}

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
                stringstream ss1(to.substr(3));
                string to1;
                string name;
                int efficiency;
                int powerContribution;
                int powerDraw;
                int count = 0;
                while(getline(ss1, to1, ' '))
                {
                    switch(count)
                    {
                        case 0:
                            name = to1;
                            break;
                        case 1:
                            efficiency = stoi(to1);
                            break;
                        case 2:
                            powerContribution = stoi(to1);
                            break;
                        case 3:
                            powerDraw = stoi(to1);
                            break;
                    }
                    count++;
                }

                if(name == "ice" || name == "turbocharger")
                {
                    Engine* engine = this->engineering->getEngine();
                    Part* part = engine->makePartExperimental(name, efficiency, powerContribution, powerDraw);
                    string partName = "Part_" + to_string(partCounter);
                    containerSet->addItem(partName, part);
                    partCounter++;
                }
                else if(name == "mguk" || name == "mguh" || name == "energystore" || name == "ers")
                {
                    Electronics* electronics = this->engineering->getElectronics();
                    Part* part = electronics->makePartExperimental(name, efficiency, powerContribution, powerDraw);
                    string partName = "Part_" + to_string(partCounter);
                    containerSet->addItem(partName, part);
                    partCounter++;
                }
                else if(name == "chassis")
                {
                    Chassis* chassis = this->engineering->getChassis();
                    Part* part = chassis->makePartExperimental(name, efficiency, powerContribution, powerDraw);
                    string partName = "Part_" + to_string(partCounter);
                    containerSet->addItem(partName, part);
                    partCounter++;
                }
                else if(name == "drs" || name == "bargeboard")
                {
                    Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
                    Part* part = aerodynamics->makePartExperimental(name, efficiency, powerContribution, powerDraw);
                    string partName = "Part_" + to_string(partCounter);
                    containerSet->addItem(partName, part);
                    partCounter++;
                }
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


void RacingStrategyInterface::addIce(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Engine* engine = this->engineering->getEngine();
        ResearchAndDevelopmentDepartment* RaD = new Engine();
        RaD->setPart(engine->makePartExperimental("ice", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addTurboCharger(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Engine* engine = this->engineering->getEngine();
        ResearchAndDevelopmentDepartment* RaD = new Engine();
        RaD->setPart(engine->makePartExperimental("turbocharger", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addMguk(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Electronics* electronics = this->engineering->getElectronics();
        ResearchAndDevelopmentDepartment* RaD = new Electronics();
        RaD->setPart(electronics->makePartExperimental("mguk", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addMguh(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Electronics* electronics = this->engineering->getElectronics();
        ResearchAndDevelopmentDepartment* RaD = new Electronics();
        RaD->setPart(electronics->makePartExperimental("mguh", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addEngergyStore(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Electronics* electronics = this->engineering->getElectronics();
        ResearchAndDevelopmentDepartment* RaD = new Electronics();
        RaD->setPart(electronics->makePartExperimental("energystore", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addErs(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Electronics* electronics = this->engineering->getElectronics();
        ResearchAndDevelopmentDepartment* RaD = new Electronics();
        RaD->setPart(electronics->makePartExperimental("ers", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addChasis(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Chassis* chassis = this->engineering->getChassis();
        ResearchAndDevelopmentDepartment* RaD = new Chassis();
        RaD->setPart(chassis->makePartExperimental("chassis", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addDrs(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        ResearchAndDevelopmentDepartment* RaD = new Aerodynamics();
        RaD->setPart(aerodynamics->makePartExperimental("drs", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::addBargeBoard(double efficiency, double pcontrib, double pdraw)
{
    if(!this->isFirst &&
       efficiency <= 10 &&
       efficiency >= 0 &&
       pcontrib <= 10 &&
       pcontrib >= 0 &&
       pdraw <= 10 &&
       pdraw >= 0)
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        ResearchAndDevelopmentDepartment* RaD = new Aerodynamics();
        RaD->setPart(aerodynamics->makePartExperimental("bargeboard", efficiency/10, pcontrib/10, pdraw/10));
        this->racingStrategy->add(RaD);
    }
}

void RacingStrategyInterface::setResult(Result *newResult)
{
    this->result = newResult;
}

void RacingStrategyInterface::generateReport()
{
    this->result->setRaceStrategy(this->racingStrategy->getStrategy());
}

void RacingStrategyInterface::setStrategy(RacingStrategy *raceStrategy)
{
    this->racingStrategy = raceStrategy;
}
