#include "RaceResults.h"

void RaceResults::setState(float* state, int session) {
	this->results[session] = state;
	for (int i = 0; i < 20; i++)
	{
		std::cout << "Time for car " << i << " in session " << session << " was: " << state[i] << std::endl;
	}
	if (session == 2)
	{
		float t1 = state[18];
		float t2 = state[19];
		std::sort(state, state + 20);
		for (int i = 0; i < 20; i++)
		{
			if (state[i] == t1)
			{
				std::cout << "Car 1 finished in position " << i << std::endl;
			}
			if (state[i] == t2)
			{
				std::cout << "Car 2 finished in position " << i << std::endl;
			}
		}
	}
}