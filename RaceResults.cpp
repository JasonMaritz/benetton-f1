#include "RaceResults.h"

void RaceResults::setState(float* state, int session) {
	this->results[session] = state;
}
