#ifndef Result_h
#define Result_h

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Result
{
private:
	string DriverReport;
	string TrackReport;
	string RaceStrategyReport;
	string CarReport;
	vector<string> PartsReport;

public:
	void setDriverReport(string Report);
	void setTrackReport(string Report);
	void setRaceStrategy(string Report);
	void setCarReport(string Report);
	void setPartsReport(vector<string> PartsReport);
	void printReport();
};

#endif // !Result_h

