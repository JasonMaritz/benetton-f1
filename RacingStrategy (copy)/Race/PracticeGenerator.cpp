#include "PracticeGenerator.h"

void PracticeGenerator::handleChanges(Times* context)
{
	context->setState(new QualifyingGenerator());
}

float* PracticeGenerator::getTime(F1Car* car)
{
	float totalTimes [20];
	for (int i = 0; i < 18; i++)
	{
		int newRandValue = rand() % 100;
	    totalTimes[i] = track->getLength() / track->getSpeed() - ((10 + newRandValue % (91)/10));
	}
	for (int i = 17; i < 20; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() - car->getPerformance();
	}
	return totalTimes;
}
