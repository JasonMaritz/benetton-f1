#include "Race.h"

Race::Race() {
	ContainerRoute r = new ContainerRoute();
	this->containerSet = r.getContainers();
	this->times = new Times(breakContainer(c));
}

Race::Race(RaceStrategy::RacingStrategy* strategy, Track* Track) {
	this->raceStrategy = strategy;
	this->track = track;
	this->containerSet = strategy->buildAndGetContainerSet();
	this->times = new Times(breakContainer(c));
}

std::vector<Parts*> Race::breakContainer(ContainerSet* c) {
	// 5 tyres
	// 9 parts
	std::vector<Parts*> parts = new std::vector<Parts*>();
	for (int i = 1; i < 10; i++)
	{
		s = to_string(i);
		Part p = (Part) c->getItem("Part_" + s);
		parts.push_back(p);
	}
	return parts;
}

std::vector<PackedItem*> Race::breakContainer(ContainerSet* c) {
	// 5 tyres
	// 9 parts
	std::vector<Tyre*> tyres = new std::vector<Tyre*>();
	for (int i = 1; i < 6; i++)
	{
		s = to_string(i);
		Tyre p = (Tyre) c->getItem("Tyre_" + s);
		tyres.push_back(p);
	}
	return tyres;
}