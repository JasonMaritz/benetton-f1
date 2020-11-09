#ifndef TIMES_H
#define TIMES_H
#include <vector>
#include "TimeGenerator.h"
#include "ResultOriginator.h"
#include "../F1Car/include/RaceBuilderDir.h"
#include "RaceResults.h"
#include "../Tyres/Tyre.h"

class TimeGenerator;
class ResultOriginator;

class Times
{

private:
    TimeGenerator* state{};
	F1Car* car{};
	std::vector<Part*> ourParts;
	std::vector<Tyre*> ourTyres;
	RaceBuilderDir* f1Builder{};
	std::vector<RaceResults*> pastResults;
	ResultOriginator* resultOriginator{};

public:
	///@param ourParts Recieves tha parts from the Raceclass which instatiates Times - used in generateCars() to make the cars
	Times();
	///Fetchs the time from the TimeGenerator
	float* getTime();
	///Specifies which session is being used
	void setState(TimeGenerator* state);
	///Creates our cars from the given parts in the Parts vector
	void generateCars();
	///Add a result to the vector ofpast results
	void addResults(RaceResults* results);

	void setParts(std::vector<Part*> parts);
	void setTyres(std::vector<Tyre*> tyres);
};

#endif
