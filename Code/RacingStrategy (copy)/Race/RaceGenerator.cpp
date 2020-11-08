#include "RaceGenerator.h"
#include <iostream>

void RaceGenerator::handleChanges(Times* context) {
	context->setState(NULL);
	std::cout << "Race weekend concluded! No new session to move to." << std::endl;
}

float* RaceGenerator::getTime(F1Car* car)
{
    // totalTime = (length / speed) =- adv/disad * laps + (low chance boolean of major mistake)
    float totalTimes[20];
    for (int i = 0; i < 18; i++)
    {
        totalTimes[i] = (track->getLength() / track->getSpeed() + 0.1 + rand() % (1 - 0.1)) * 50;
        if (rand() % 100 > 96)
        {
            totalTimes[i] += 120;
        }

    }
    for (int i = 17; i < 20; i++)
    {
        totalTimes[i] = track->getLength() / track->getSpeed() + car->getPerformance() * 50;
        if (rand() % 100 > 96)
        {
            totalTimes[i] += 120;
        }
    }
    return totalTimes;
}