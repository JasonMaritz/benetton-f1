#include "PracticeGenerator.h"

void PracticeGenerator::handleChanges(Times* context) {
	context->setState(new QualifyingGenerator());
}

int PracticeGenerator::getTime(F1Car* car) {
	float[20] totalTimes;
	for (int i = 0; i < 18; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() + 0.1 + rand() % (1 - 0.1); 
	}
	for (int i = 17; i < 20; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() + car.getPerformance();
	}
	return totalTimes;
}
