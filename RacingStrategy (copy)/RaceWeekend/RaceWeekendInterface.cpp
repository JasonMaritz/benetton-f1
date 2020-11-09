//
// Created by chrissi-boi on 2020/11/09.
//

#include "RaceWeekendInterface.h"
#include "../Shipping/Shipper.h"

RaceWeekendInterface::RaceWeekendInterface(string ContainerName, Track *newTrack)
{
    Shipper* shipper = Shipper::getInstance();
    ContainerSet* containerSet = shipper->getHighPriority()->get(ContainerName);
    this->breakContainerIntoParts(containerSet);
    this->breakContainerIntoTyres(containerSet);
    this->track = newTrack;
    this->engineering = Engineering::getInstance();
    this->CarBuilder = new RaceBuilderDir();
    this->buildCar();
}

void RaceWeekendInterface::StartRaceWeekend()
{

}

void RaceWeekendInterface::buildCar()
{
    if(!isInOurParts("ice"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("ice");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("turbocharger"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("turbocharger");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("mguk"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguk");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("mguh"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguh");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("energystore"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("energystore");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("ers"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("ers");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("chassis"))
    {
        Chassis* chassis = this->engineering->getChassis();
        Part* newPart = chassis->makePart("chassis");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("drs"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("drs");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("bargeboard"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("bargeboard");
        this->ourParts.push_back(newPart);
    }

    for(int i = 0; i < 20; i++)
    {
        this->carArray[i] = this->CarBuilder->buildCar(this->ourParts);
    }
}

void RaceWeekendInterface::breakContainerIntoParts(ContainerSet* container)
{
    for (int i = 1; i < 10; i++)
    {
        Part* part = (Part *)(container->getItem("Part_" + to_string(i)));
        if(part != nullptr)
        {
            this->ourParts.push_back(part);
        }
    }
}

void RaceWeekendInterface::breakContainerIntoTyres(ContainerSet* container)
{
    for (int i = 1; i < 6; i++)
    {
        this->ourTyres.push_back((Tyre*)(container->getItem("Tyre_" + to_string(i))));
    }
}

bool RaceWeekendInterface::isInOurParts(string partName)
{
    vector<Part*>::iterator it;
    for(it = this->ourParts.begin(); it < this->ourParts.end(); it++)
    {
        Part* temp = (Part*)((*it));
        stringstream ss(temp->getType());
        string to;
        getline(ss, to, ' ');
        if(to == partName)
        {
            return true;
        }
    }
    return false;
}


