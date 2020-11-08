#ifndef RACERESULTS_H
#define RACERESULTS_H

class RaceResults {

private:
	float* results[3];
public:
	///As this is the Memento class, setState defines the results field for this object
	///@param state Sets the array values for a particular session
	///@param result Defines which session said values apply to
	void setState(float* state, int result);
};

#endif