///
/// Created by FJ Redelinghuys on 08/11/2020
/// 


#ifndef Driver_h
#define Driver_h

#include <string>
#include "../Simulation/Result.h"
#include "../Track/Track.h"

using namespace std;

class Driver
{
private:
	string Name;
	Result* result;

public:
	/// @brief Driver Constructor
	/// @param name Drivers name
	Driver(string name);

	/// @brief Generates report for driver
	/// @param track specifies the track
	void generateReport(Track* track);

	/// @brief Sets the result for driver
	/// @param result same pointer as rest of simulation 
	void setResult(Result* result);
};


#endif // !Driver_h