#ifndef TIMES_H
#define TIMES_H
#include <vector>
#include "F1Builder.h"
#include "TimeGenerator.h"
#include 

class Times {

private:
	TimeGenerator* state;
	std::vector<F1Car*> carList;
	std::vector<PackedItem*> ourParts;
	F1Builder* f1Builder;

public:
	///@param ourParts Recieves tha parts from the Raceclass which instatiates Times - used in generateCars() to make the cars
	Times(std::vector<PackedItem*> ourParts);
	///Changes the session being run to the next
	void change();
	///Fetchs the time from the TimeGenerator
	int* getTime();
	///Specifies which session is being used
	void setState(TimeGenerator* state);
	///Creates our cars from the given parts in the Parts vector
	void generateCars();
};

#endif
