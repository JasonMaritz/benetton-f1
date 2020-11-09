#include "Race.h"
#include "../Container/ContainerRoute.h"


Race::Race(RacingStrategy* strategy, Track* newTrack)
{
	this->raceStrategy = strategy;
	this->track = newTrack;
    this->racingStrategyInterface = new RacingStrategyInterface();
	this->racingStrategyInterface->setStrategy(this->raceStrategy);
	this->containerSet = this->racingStrategyInterface->buildAndGetContainerSet();
	this->times = new Times();
	this->breakContainerParts(this->containerSet);
	this->breakContainerTyres(this->containerSet);
}

void Race::breakContainerParts(ContainerSet* c)
{
	// 9 parts
	for (int i = 1; i < 10; i++)
	{
		this->times->addPart((Part *)(c->getItem("Part_" + to_string(i))));
	}
}

void Race::breakContainerTyres(ContainerSet* c) {
	// 5 tyres
	for (int i = 1; i < 6; i++)
	{
		this->times->addTyre((Tyre*)(c->getItem("Tyre_" + to_string(i))));
	}
}

void Race::generateResults()
{

}
