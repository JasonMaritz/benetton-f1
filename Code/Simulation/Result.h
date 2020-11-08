#ifndef Result_h
#define Result_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Result
{
private:
	string DriverReport;
	string TrackReport;
	string RaceStrategyReport;
	string CarReport;
	vector<string> PartsReport;

	bool checkAllSet();

public:
	/// @brief Sets the driver report
	/// @param Report of driver
	void setDriverReport(string Report);

	/// @brief Set the track report
	/// @param Report of track
	void setTrackReport(string Report);

	/// @brief Set the race strat report 
	/// @param Report of race strat
	void setRaceStrategy(string Report);

	/// @brief Set the car report
	/// @param Report of car
	void setCarReport(string Report);

	/// @brief Set the vector<string> of each parts report
	/// @param PartsReport contains 
	void setPartsReport(vector<string> PartsReport);

	/// @brief prints the report out to screen without racestrat
	void printReport();

	/// @brief prints the report out to textfile with SimUniqueID as the name
	/// @param SimUniqueID UniqueID for the textfile
	void StoreResultToTF(string SimUniqueID);

	/// @brief This is used to simulate variations
	/// @param min double value for random function
	/// @param max double value for random function
	/// @param decimal used in variation function
	/// @return variation as a double
	double SimulationVariation(double min, double max, int decimal);
};

#endif // !Result_h

