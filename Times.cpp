#include "Times.h"

Times::Times(std::vector<PackedItem*> ourParts;) {
	this->ourParts = ourParts;
	this->f1Builder = new f1Builder();
}

void Times::change() {
	
}

float* Times::getTime() {
	return state->getTime()
}

void Times::setState(TimeGenerator* state) {
	this->state = state;
}

void Times::generateCars() {
	F1car* car = f1Builder->newCar(ourParts);
}
