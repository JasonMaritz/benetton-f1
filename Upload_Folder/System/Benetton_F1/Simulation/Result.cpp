#include "Result.h"

bool Result::checkAllSet()
{
	if (DriverReport.length() <= 0) { return false; }
	if (TrackReport.length() <= 0) { return false; }
	if (RaceStrategyReport.length() <= 0) { return false; }
	if (CarReport.length() <= 0) { return false; }
	for (vector<string>::iterator it = PartsReport.begin(); it != PartsReport.end(); it++)
	{
		if ((*it).length() <= 0) { return false; }
	}
	return true;
}

void Result::setDriverReport(string Report)
{
	DriverReport = Report;
}

void Result::setTrackReport(string Report)
{
	TrackReport = Report;
}

void Result::setRaceStrategy(string Report)
{
	RaceStrategyReport = Report;
}

void Result::setCarReport(string Report)
{
	CarReport = Report;
}

void Result::setPartsReport(vector<string> PartsReport)
{
	this->PartsReport = PartsReport;
}

void Result::printReport()
{
	cout << "Result Summary:" << endl;
	cout << endl;

	cout << "Driver report:" << endl;
	cout << DriverReport << endl;

	cout << "Track report:" << endl;
	cout << TrackReport << endl;

	cout << "Car report:" << endl;
	cout << CarReport << endl << endl;;

	cout << "Finished mini report" << endl;
}

void Result::StoreResultToTF(string SimUniqueID)
{
	if (!checkAllSet()) {
		throw "All reports not set";
	}

	ofstream fs(SimUniqueID + ".txt", ios::app);
	fs << DriverReport;
	fs << TrackReport;
	fs << RaceStrategyReport;
	fs << CarReport;
	
	for (vector<string>::iterator it = PartsReport.begin(); it != PartsReport.end(); it++)
	{
		fs << (*it);
	}
	
	fs.close();
	cout << "Finished print to textfile: " + SimUniqueID + ".txt";
}

double Result::SimulationVariation(double min, double max, int decimal)
{
	int minI = min * decimal;
	int maxI = max * decimal;
	int variantion = minI + (rand() % (maxI - minI));
	if (rand() % 2 == 0) { variantion * -1; }
	return variantion / decimal;
}
