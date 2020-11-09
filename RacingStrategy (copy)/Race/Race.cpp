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
	this->times->setParts(this->breakContainerParts(this->containerSet));
	this->times->setTyres(this->breakContainerTyres(this->containerSet));
}

std::vector<Part*> Race::breakContainerParts(ContainerSet* c) {
	// 5 tyres
	// 9 parts
	auto* parts = new std::vector<Part*>();
	for (int i = 1; i < 10; i++)
	{
		Part* p = dynamic_cast<Part *>(c->getItem("Part_" + to_string(i)));
		parts->push_back(p);
	}
	return reinterpret_cast<const vector<Part *> &>(parts);
}

std::vector<Tyre*> Race::breakContainerTyres(ContainerSet* c) {
	// 5 tyres
	// 9 parts
	auto* tyres = new std::vector<Tyre*>();
	for (int i = 1; i < 6; i++)
	{
		Tyre* p = dynamic_cast<Tyre *>(c->getItem("Tyre_" + to_string(i)));
		tyres->push_back(p);
	}
	return reinterpret_cast<const vector<Tyre *> &>(tyres);
}

void Race::generateResults()
{

}
