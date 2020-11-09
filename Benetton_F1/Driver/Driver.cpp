///
/// Created by FJ Redelinghuys on 08/11/2020
/// 


#include "Driver.h"

Driver::Driver(string name)
{
	Name = name;
}

void Driver::generateReport(Track* track)
{
	string report;

	report = "Driver: " + Name + " took part in simulation\n ";
	report += "Fatigue on driver due to track: " + track->getFatigue();
	result->setDriverReport(report);
}

void Driver::setResult(Result* result)
{
	this->result = result;
}
