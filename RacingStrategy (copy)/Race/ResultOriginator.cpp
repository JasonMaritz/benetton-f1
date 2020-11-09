#include "ResultOriginator.h"

RaceResults* ResultOriginator::createResults()
{
	RaceResults* r = new RaceResults();
	float results [3];
	int pos1;
	int pos2;
	for (int i = 0; i < 3; i++) 	// for each car in the race, we need to generate results
	{
		float* t = times->getTime();
		r->setState(t, i);
		pos1 = 1;
		pos2 = 1;
		for (int j = 0; j < 18; j++)
		{
			if (t[19] > t[j])
			{
				pos1++;
			}
			if (t[18] > t[j])
			{
				pos2++;
			}
		}
	}
	std::cout << "Our cars came in positions " << pos1 << " and " << pos2 << std::endl;
		int points = 0;
		switch (pos1)
		{
		case 1:
			points = 25;
			break;
		case 2:
			points = 18;
			break;
		case 3:
			points = 15;
			break;
		case 4:
			points = 12;
			break;
		case 5:
			points = 10;
			break;
		case 6:
			points = 8;
			break;
		case 7:
			points = 6;
			break;
		case 8:
			points = 4;
			break;
		case 9:
			points = 2;
			break;
		case 10:
			points = 1;
			break;
		default:
			break;
		}
		std::cout << "Car 1 points: " << points << std::endl;
		switch (pos2)
		{
		case 1:
			points = 25;
			break;
		case 2:
			points = 18;
			break;
		case 3:
			points = 15;
			break;
		case 4:
			points = 12;
			break;
		case 5:
			points = 10;
			break;
		case 6:
			points = 8;
			break;
		case 7:
			points = 6;
			break;
		case 8:
			points = 4;
			break;
		case 9:
			points = 2;
			break;
		case 10:
			points = 1;
			break;
		default:
			break;
		}
		std::cout << "Car 2 points: " << points << std::endl;
	return r;
}

void ResultOriginator::setResults(RaceResults* results)
{
	this->state = results;
}