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

std::vector<PackedItem*> Race::breakContainer(ContainerSet* c) {
	// 5 tyres
	// 9 parts
	std::vector<Parts*> parts = new std::vector<Parts*>();
	for (int i = 1; i < 10; i++)
	{
		s = to_string(i);
		Part p = (Part) c->getItem("part_" + s);
		parts.push_back(p);
	}
	return parts;
}