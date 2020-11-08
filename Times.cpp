#include "Times.h"

Times::Times(std::vector<PackedItem*> ourParts;) {
	this->ourParts = ourParts;
}

void Times::change() {
	
}

int Times::getTime() {
	for (int i = 0; i < 20; i++)
	{
		return state->getTime(carList.at(i));
	}
	
	
}

void Times::setState(TimeGenerator* state) {
	this->state = state;
}

void Times::generateCars() {
	for (int i = 0; i < 2; i++)		// create 2 of our own cars
	{
		F1car* ourCar = f1Builder->newCar(ourParts);	// so the two last cars are the ones that are *actually* ours
		carList.push_back(ourCar);
	}
}
