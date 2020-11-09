//
// Created by jason on 2020/11/03.
//

#include "../include/F1Car.h"

F1Car::~F1Car() {
    delete res;
    delete bargeboard;
    delete drs;
    delete ice;
    delete turboCharger;
    delete chassisPart;
    delete mguk;
    delete mguh;
    delete ers;
    delete energyStore;
}

double F1Car::getPerformance() {
    double res = 0;
    res += bargeboard->getPerformance();
    res += drs->getPerformance();
    res += ice->getPerformance();
    res += turboCharger->getPerformance();
    res += chassisPart->getPerformance();
    res += ers->getPerformance();
    res += mguh->getPerformance();
    res += mguk->getPerformance();
    res += energyStore->getPerformance();
    res /= 9;
    return res;
}

void F1Car::generateReport()
{
    std::vector<Part*> parts = generateParts();
    string Car_report = "Car used in simulation \n";
    double Carperformance = getPerformance();
    if (Carperformance + res->SimulationVariation(0, 0.3, 10) > 0)
    {
        Carperformance = Carperformance + res->SimulationVariation(0, 0.3, 10);
    }
    Car_report += "Car achieved a simulated estimated performance of: " + to_string(Carperformance);
    res->setCarReport(Car_report);

    vector<string> Parts_report;
    Parts_report.push_back("Parts used in car \n");
    for (auto it = parts.begin(); it != parts.end(); it++)
    {
        double performance = (*it)->getPerformance();
        if (performance + res->SimulationVariation(0, 0.2, 10) > 0)
        {
            performance = performance + res->SimulationVariation(0, 0.2, 10);
        }
        string tempreport = (*it)->getType() + " achieved a simulated estimated performance of: " +
                            to_string(performance);
        Parts_report.push_back(tempreport);
    }

    res->setPartsReport(Parts_report);
}

std::vector<Part *> F1Car::generateParts() {
    std::vector<Part *> ret;
    ret.push_back((Part*)bargeboard);
    ret.push_back((Part*)drs);
    ret.push_back((Part*)chassisPart);
    ret.push_back((Part*)ice);
    ret.push_back((Part*)turboCharger);
    ret.push_back((Part*)mguk);
    ret.push_back((Part*)mguk);
    ret.push_back((Part*)energyStore);
    ret.push_back((Part*)ers);
    return ret;
}

void F1Car::setDriverName(string name)
{
    this->driverName = name;
}

void F1Car::setCarName(string name)
{
    this->carName = name;
}

string F1Car::getDriverName()
{
    return this->driverName;
}

string F1Car::getCarName()
{
    return this->carName;
}

void F1Car::setQualifyingTime(double time)
{
    this->qualifyingTime = time;
}

void F1Car::setLapTime(double time)
{
    this->lapTime = time;
}

void F1Car::setRaceTime(double time)
{
    this->raceTime = time;
}

double F1Car::getQualifyingTime()
{
    return this->qualifyingTime;
}

double F1Car::getLapTime()
{
    return this->lapTime;
}

double F1Car::getRaceTime()
{
    return this->raceTime;
}
