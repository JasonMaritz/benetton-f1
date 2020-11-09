#ifndef TIMES_H
#define TIMES_H
#include <vector>
#include <sstream>
#include "TimeGenerator.h"
#include "ResultOriginator.h"
#include "../F1Car/include/RaceBuilderDir.h"
#include "RaceResults.h"
#include "../Tyres/Tyre.h"
#include "../R&D/include/Engineering.h"

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
	Engineering* engineering;

public:
	Times();
	///Fetchs the time from the TimeGenerator
	float* getTime();
	///Specifies which session is being used
	void setState(TimeGenerator* state);
	///Creates our cars from the given parts in the Parts vector
	void generateCars();
	///Add a result to the vector of past results
	void addResults(RaceResults* results);
    void addPart(Part* newPart);
    void addTyre(Tyre* newTyre);

private:
    bool isInOurParts(string partName);
};

#endif
