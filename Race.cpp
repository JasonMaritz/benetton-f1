#include "Race.h"

Race::Race() {

}

Race::Race(RaceStrategy::RacingStrategy* RacingStrategy, Track* Track) {
	this->raceStrategy = RacingStrategy;
	this->track = track;
}

std::vector<PackedItem*> breakContainer(ContainerSet* c) {
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