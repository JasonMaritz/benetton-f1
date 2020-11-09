#include "Times.h"

Times::Times()
{
	this->f1Builder = new RaceBuilderDir();
	this->engineering = Engineering::getInstance();
}

float* Times::getTime()
{
	return state->getTime(this->car);
}

void Times::setState(TimeGenerator* state)
{
	this->state = state;
}

void Times::generateCars()
{
    if(!isInOurParts("ice"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("ice");
        this->addPart(newPart);
    }

    if(!isInOurParts("turbocharger"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("turbocharger");
        this->addPart(newPart);
    }

    if(!isInOurParts("mguk"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguk");
        this->addPart(newPart);
    }

    if(!isInOurParts("mguh"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguh");
        this->addPart(newPart);
    }

    if(!isInOurParts("energystore"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("energystore");
        this->addPart(newPart);
    }

    if(!isInOurParts("ers"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("ers");
        this->addPart(newPart);
    }

    if(!isInOurParts("chassis"))
    {
        Chassis* chassis = this->engineering->getChassis();
        Part* newPart = chassis->makePart("chassis");
        this->addPart(newPart);
    }

    if(!isInOurParts("drs"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("drs");
        this->addPart(newPart);
    }

    if(!isInOurParts("bargeboard"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("bargeboard");
        this->addPart(newPart);
    }

    car = f1Builder->buildCar(this->ourParts);
}

void Times::addResults(RaceResults *results)
{
    this->pastResults.push_back(results);
}

void Times::addPart(Part* newPart)
{
    this->ourParts.push_back(newPart);
}

void Times::addTyre(Tyre* newTyre)
{
    this->ourTyres.push_back(newTyre);
}

bool Times::isInOurParts(string partName)
{
    vector<Part*>::iterator it;
    for(it = ourParts.begin(); it < ourParts.end(); it++)
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
