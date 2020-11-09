#include "QualifyingGenerator.h"

void QualifyingGenerator::handleChanges(Times* context) {
	context->setState(new RaceGenerator());
}

float* QualifyingGenerator::getTime(F1Car* car) {
	float totalTimes[20];
	for (int i = 0; i < 18; i++)
	{
        int newRandValue = rand() % 100;
	    totalTimes[i] = track->getLength() / (float)track->getSpeed() - (float)((10 + newRandValue % 90)/10.0) - 0.5;
	}
	for (int i = 17; i < 20; i++)
	{
		totalTimes[i] = track->getLength() / track->getSpeed() - car->getPerformance() - 0.5;
	}
	return totalTimes;
}