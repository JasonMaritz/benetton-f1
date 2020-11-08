#include "QualifyingGenerator.h"

void QualifyingGenerator::handleChanges(Times* context) {
	context->setState(new RaceGenerator());
}

int QualifyingGenerator::getTime(F1Car* car) {
	//float totalTime = //(length / speed) +- advantage - qualification focus advantage
	float[20] totalTimes;
	for (int i = 0; i < 18; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() + 0.1 + rand() % (1 - 0.1) - 0.5; 
	}
	for (int i = 17; i < 20; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() + car.getPerformance() - 0.5;
	}
	return totalTimes;
}