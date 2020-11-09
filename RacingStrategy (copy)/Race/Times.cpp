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

void Times::setParts(std::vector<Part *> parts)
{
    this->ourParts = parts;
}

void Times::setTyres(std::vector<Tyre *> tyres)
{
    this->ourTyres = tyres;
}
