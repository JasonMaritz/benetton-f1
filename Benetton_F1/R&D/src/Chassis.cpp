//
// Created by jason on 2020/11/03.
//

#include "../include/Chassis.h"
#include "../../PartsFactory/include/ChaFactoryExperimental.h"

Chassis::Chassis()
{
    myFactory = new ChaFactory();
    myFactoryExperimental = new ChaFactoryExperimental();
}

Part *Chassis::makePart(std::string type)
{
    return myFactory->produce(type);
}

Part *Chassis::makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw)
{
    Part* p = myFactory->produce(type);
    p->mutatePD(pdraw);
    p->mutatePC(pcontrib);
    p->mutateEf(efficiency);
    return  p;
}

void Chassis::setBest(Part *newBest)
{
    myFactory->setDefault(newBest);
    myFactoryExperimental->setDefault(newBest);
}

void Chassis::developParts()
{
    experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("chassis"));
}
