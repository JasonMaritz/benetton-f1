//
// Created by chrissi-boi on 2020/11/09.
//

#include "RaceWeekendInterface.h"
#include "../Shipping/Shipper.h"
#include "Qualifying.h"
#include "Race.h"

RaceWeekendInterface::RaceWeekendInterface(string ContainerName, Track *newTrack)
{
    this->addDrivers();
    Shipper* shipper = Shipper::getInstance();
    ContainerSet* containerSet = shipper->getHighPriority()->get(ContainerName);
    this->breakContainerIntoParts(containerSet);
    this->breakContainerIntoTyres(containerSet);
    this->track = newTrack;
    this->engineering = Engineering::getInstance();
    this->CarBuilder = new RaceBuilderDir();
    this->buildCar();
}

void RaceWeekendInterface::StartRaceWeekend()
{
    auto* qualifying = new Qualifying(this->carArray);
    F1Car** tempArray = qualifying->StartQualifying();
    cout << endl << "Qualifying Results: " << endl;
    for(int i = 0; i < 20; i++)
    {
        this->carArray[i] = tempArray[i];
        double qualifyingTime = this->carArray[i]->getQualifyingTime();
        string carN = this->carArray[i]->getCarName();
        string driverN = this->carArray[i]->getDriverName();
        cout << driverN << " in " << carN << " qualified in " << qualifyingTime << " minutes." << endl;
    }
    cout << endl;

    auto* race = new Race(this->carArray, this->track, this->ourTyres);
    tempArray = race->StartRace();
    cout << endl << "Podium: " << endl;
    for(int i = 0; i < 20; i++)
    {
        this->carArray[i] = tempArray[i];
        if(i < 3)
        {
            double raceT = this->carArray[i]->getRaceTime();
            string carN = this->carArray[i]->getCarName();
            string driverN = this->carArray[i]->getDriverName();
            if(i == 0)
            {
                cout << "1st Place: " << driverN << " in " << carN << " finished the race in " << raceT << " minutes" << endl;
            }
            else if(i == 1)
            {
                cout << "2nd Place: " << driverN << " in " << carN << " finished the race in " << raceT << " minutes" << endl;
            }
            else if(i == 2)
            {
                cout << "3rd Place: " << driverN << " in " << carN << " finished the race in " << raceT << " minutes" << endl;
            }
        }
    }
}

void RaceWeekendInterface::buildCar()
{
    if(!isInOurParts("ice"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("ice");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("turbocharger"))
    {
        Engine* engine = this->engineering->getEngine();
        Part* newPart = engine->makePart("turbocharger");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("mguk"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguk");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("mguh"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("mguh");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("energystore"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("energystore");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("ers"))
    {
        Electronics* electronics = this->engineering->getElectronics();
        Part* newPart = electronics->makePart("ers");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("chassis"))
    {
        Chassis* chassis = this->engineering->getChassis();
        Part* newPart = chassis->makePart("chassis");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("drs"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("drs");
        this->ourParts.push_back(newPart);
    }

    if(!isInOurParts("bargeboard"))
    {
        Aerodynamics* aerodynamics = this->engineering->getAreodynamics();
        Part* newPart = aerodynamics->makePart("bargeboard");
        this->ourParts.push_back(newPart);
    }

    for(int i = 0; i < 20; i++)
    {
        this->carArray[i] = this->CarBuilder->buildCar(this->ourParts);
        string carName = "Car_" + to_string(i+1);
        this->carArray[i]->setCarName(carName);
        this->carArray[i]->setDriverName(this->DriverNames[i]);
        this->CarBuilder->resetCar();
    }
}

void RaceWeekendInterface::breakContainerIntoParts(ContainerSet* container)
{
    for (int i = 1; i < 10; i++)
    {
        Part* part = (Part *)(container->getItem("Part_" + to_string(i)));
        if(part != nullptr)
        {
            this->ourParts.push_back(part);
        }
    }
}

void RaceWeekendInterface::breakContainerIntoTyres(ContainerSet* container)
{
    for (int i = 1; i < 6; i++)
    {
        this->ourTyres.push_back((Tyre*)(container->getItem("Tyre_" + to_string(i))));
    }
}

bool RaceWeekendInterface::isInOurParts(string partName)
{
    vector<Part*>::iterator it;
    for(it = this->ourParts.begin(); it < this->ourParts.end(); it++)
    {
        Part* temp = (Part*)((*it));
        stringstream ss(temp->getType());
        string to;
        getline(ss, to, ' ');
        if(to == partName)
        {
            return true;
        }
    }
    return false;
}

void RaceWeekendInterface::addDrivers()
{
    this->DriverNames[0] = "Giancarlo Fisichella";
    this->DriverNames[1] = "Alexander Wurz";
    this->DriverNames[2] = "Jacques Villeneuve";
    this->DriverNames[3] = "Heinz-Harald Frentzen";
    this->DriverNames[4] = "Michael Schumacher";
    this->DriverNames[5] = "Eddie Irvine";
    this->DriverNames[6] = "David Coulthard";
    this->DriverNames[7] = "Mika Häkkinen";
    this->DriverNames[8] = "Damon Hill";
    this->DriverNames[9] = "Ralf Schumacher";
    this->DriverNames[10] = "Olivier Panis";
    this->DriverNames[11] = "Jarno Trulli";
    this->DriverNames[12] = "Jean Alesi";
    this->DriverNames[13] = "Johnny Herbert";
    this->DriverNames[14] = "Jos Verstappen";
    this->DriverNames[15] = "Rubens Barrichello";
    this->DriverNames[16] = "Jan Magnussen";
    this->DriverNames[17] = "Pedro Diniz";
    this->DriverNames[18] = "Mika Salo";
    this->DriverNames[19] = "Ricardo Rosset";
}


