#include "Times.h"

Times::Times()
{
	this->f1Builder = new RaceBuilderDir();
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
