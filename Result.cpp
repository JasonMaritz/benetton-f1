#include "Result.h"

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
	cout << CarReport << endl;

	cout << "Part report" << endl;
	for (vector<string>::iterator it = PartsReport.begin; it != PartsReport.end(); ++it)
	{
		cout << *it << endl;
	}
}
