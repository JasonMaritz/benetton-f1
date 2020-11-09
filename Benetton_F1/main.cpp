#include <iostream>
#include "Strategy/RacingStrategyInterface.h"
#include "Container/LowPriority.h"
#include "Track/Track.h"
#include "Track/africa.h"
#include "Shipping/Shipper.h"
#include "RaceWeekend/RaceWeekendInterface.h"
#include "Driver/Driver.h"
#include "Track/Asia.h"
#include "Track/Europe.h"
#include "Track/NAmerica.h"
#include "Track/SAmerica.h"
#include "TestingCenter/NonEuropeTestArea.h"
#include "TestingCenter/EuropeTestArea.h"
#include "Simulation/Simulation.h"

using namespace std;

WindTunnelCounter* wc;

void SimulationTest();
void TestingCenterTest();
Driver* DriverCreator();
string Get(string msg);
Track* TrackCreator();
bool validateContinent(string test);
bool validateTestCenter(string test);
bool validatePartType(string test);
void ReRunTest(string TestName, TestingCenter* TC);
void testLowPriority();
RacingStrategyInterface* makeStrategy();

int main()
{
    testLowPriority();

    TestingCenterTest();
    SimulationTest();
    cout << endl << endl << "Build Strategy For Race: " << endl;
    RacingStrategyInterface* rci = makeStrategy();
    ContainerSet* con = rci->buildAndGetContainerSet();
    Track* track = new africa();
    Shipper* shipper = Shipper::getInstance();
    HighPriority* highPriority = shipper->getHighPriority();
    Location location;
    location.name = "Africa";
    location.european = false;
    auto* destination = new Destination();
    destination->location = location;
    highPriority->shipSomething(destination, con, "test");

    cout << rci->getStrategy() << endl << endl;

    auto* raceWeekendInterface = new RaceWeekendInterface("test", track);
    raceWeekendInterface->StartRaceWeekend();

    return 0;
}

void testLowPriority()
{
    cout << "Routes for low priority containers (each line a new set of containers):\n";
    LowPriority lp;
    lp.destinationsFromtxt();
    lp.setupRoutes();
    lp.printRoutes();
}

RacingStrategyInterface* makeStrategy()
{
    auto* rci = new RacingStrategyInterface();
    string response;
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter the letter for the tyre you want to make: " << endl << "S: Soft" << endl << "M: Medium" << endl << "H: Hard" << endl;
        cin >> response;

        if(response == "s" || response == "S")
        {
            rci->addSoftTyre();
        }
        else if(response == "m" || response == "M")
        {
            rci->addMediumTyre();
        }
        else if(response == "h" || response == "H")
        {
            rci->addHardTyre();
        }
    }

    cout << "Do you want to add any experimental parts to the Race Strategy." << endl << "Y: Yes" << endl << "N: No" << endl;
    cin >> response;

    if(response == "y" || response == "Y")
    {
        while(true)
        {
            cout << "What part do you want to make?" << endl;
            cout << "1: ICE" << endl;
            cout << "2: Turbo Charger" << endl;
            cout << "3: MGUK" << endl;
            cout << "4: MGUH" << endl;
            cout << "5: Energy Storage" << endl;
            cout << "6: ERS" << endl;
            cout << "7: Chassis" << endl;
            cout << "8: DRS" << endl;
            cout << "9: Barge Board" << endl;
            cin >> response;
            int choice = stoi(response);

            int efficiency;
            int powerContribution;
            int powerDraw;

            cout << "Enter a value between 1 and 10 for the efficiency." << endl;
            cin >> response;
            efficiency = stoi(response);
            cout << "Enter a value between 1 and 10 for the power contribution." << endl;
            cin >> response;
            powerContribution = stoi(response);
            cout << "Enter a value between 1 and 10 for the power draw." << endl;
            cin >> response;
            powerDraw = stoi(response);

            switch (choice)
            {
                case 1:
                    rci->addIce((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 2:
                    rci->addTurboCharger((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 3:
                    rci->addMguk((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 4:
                    rci->addMguh((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 5:
                    rci->addEngergyStore((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 6:
                    rci->addErs((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 7:
                    rci->addChasis((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 8:
                    rci->addDrs((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
                case 9:
                    rci->addBargeBoard((double)efficiency, (double) powerContribution, (double) powerDraw);
                    break;
            }

            cout << "Do you want to add another experimental parts to the Race Strategy." << endl << "Y: Yes" << endl << "N: No" << endl;
            cin >> response;

            if(response == "n" || response == "N")
            {
                break;
            }
        }
    }
    cout << "Give a name for the Strategy." << endl;
    cin >> response;
    if(!response.empty())
    {
        rci->addName(response);
    }

    return rci;
}

void SimulationTest()
{
    vector<Part*> list_Part;
    Engineering* eng = Engineering::getInstance();
    Driver* driver;
    RacingStrategyInterface* racestrat = nullptr;
    Track* track;
    ContainerSet* container;
    string SimName;
    cout << "Simulation:" << endl;
    SimName = Get("Please enter name for simulation: ");
    driver = DriverCreator();
    racestrat = makeStrategy();
    track = TrackCreator();
    container = racestrat->buildAndGetContainerSet();
    for (int i = 1; i <= 9; i++)
    {
        string part_name = "Part_" + to_string(i);
        Part* parts = (Part*)container->getItem(part_name);
        if (parts != nullptr)
        {
            list_Part.push_back(parts);
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        string tyre_name = "Tyre_" + to_string(i);
        list_Part.push_back((Part*)container->getItem(tyre_name));
    }

    Result* result;
    Simulation* sim = new Simulation(SimName);
    sim->setEngineering(eng);
    sim->setDriver(driver);
    sim->setRaceStrat(racestrat);
    sim->setTrack(track);
    sim->setPartsBuildCar(list_Part);
    result = sim->RunSimulate();

    result->printReport();
    result->StoreResultToTF(SimName);
}

void TestingCenterTest()
{
    if (wc == nullptr)
    {
        wc = new WindTunnelCounter();
    }

    TestingCenter* TC;
    string TestName = Get("Please enter name for test: ");


    cout << "Testing Center: " << endl;
    string msg = "Please select a testing center: \n*)NonEurope\n*)Europe\n";
    string center = "";
    while (!validateTestCenter(center))
    {
        center = Get(msg);
    }

    for (int i = 0; i < center.length(); i++)
    {
        center[i] = toupper(center[i]);
    }

    if (center == "EUROPE")
    {
        TC = new EuropeTestArea(wc);
    }
    else
    {
        TC = new NonEuropeTestArea(wc);
    }

    vector<Part*> partList;
    msg = "Please provide a budget for this test center: ";
    string budget = "0";
    while (stoi(budget)<= 0 )
    {
        budget = Get(msg);
    }

    int ibudget = stoi(budget);
    Engineering* eng = Engineering::getInstance();
    eng->setBudget(ibudget);
    eng->develop();

    msg = "Please select a type of part: \n*)Engine\n*)Chassis\n*)Electronics\n*)Aerodynamics\n";
    string type = "";
    while (!validatePartType(type))
    {
        type = Get(msg);
    }

    for (int i = 0; i < type.length(); i++)
    {
        type[i] = toupper(type[i]);
    }


    if (type == "AERODYNAMIC")
    {
        if (eng->getAreodynamics())
        {
            partList = eng->getAreodynamics()->getExperimentalParts();
        }
        else
        {
            cout << "No aerodynamic part was developed. Please provide a bigger budget" << endl;
            return;
        }
    }
    if (type == "CHASSIS")
    {
        if (eng->getChassis())
        {
            partList = eng->getChassis()->getExperimentalParts();
        }
        else
        {
            cout << "No Chassis part was developed. Please provide a bigger budget" << endl;
            return;
        }
    }
    if (type == "ELECTRONIC")
    {
        if (eng->getElectronics())
        {
            partList = eng->getElectronics()->getExperimentalParts();
        }
        else
        {
            cout << "No electronic part was developed. Please provide a bigger budget" << endl;
            return;
        }
    }
    if (type == "ENGINE")
    {
        if (eng->getEngine())
        {
            partList = eng->getEngine()->getExperimentalParts();
        }
        else
        {
            cout << "No engine part was developed. Please provide a bigger budget" << endl;
            return;
        }
    }

    for (vector<Part*>::iterator it = partList.begin(); it != partList.end(); it++)
    {
        if ((*it) != NULL)
        {
            TC->addToTestQueue((*it));
        }
    }

    ReRunTest(TestName, TC);
}

Driver* DriverCreator()
{
    cout << "Driver creator:" << endl;
    string DriverName = Get("Please enter a driver name: ");
    Driver* drv = new Driver(DriverName);
    return drv;
}

string Get(string msg)
{
    string result = "";
    while (result.length() <= 0)
    {
        cout << msg;
        cin >> result;
    }
    return result;
}

Track* TrackCreator()
{
    Track* track = nullptr;
    cout << "Track creator: " << endl;
    string continent = "";

    while (!validateContinent(continent))
    {
        string msg = "Please enter a continent:\nUse the following:\n*)AFRICA\n*)ASIA\n*)EUROPE\n*)NORTH AMERICA\n*)SOUTH AMERICA\n";
        continent = Get(msg);
    }

    for (int i = 0; i < continent.length(); i++)
    {
        continent[i] = toupper(continent[i]);
    }

    if (continent == "AFRICA") {track = new africa();}
    if (continent == "ASIA") {track = new Asia();}
    if (continent == "EUROPE") {track = new Europe();}
    if (continent == "NORTH AMERICA") { track = new NAmerica(); }
    if (continent == "SOUTH AMERICA") { track = new SAmerica(); }
    return track;
}

bool validateContinent(string test)
{
    for (int i = 0; i < test.length(); i++)
    {
        test[i] = toupper(test[i]);
    }

    if (test == "AFRICA") { return true; }
    if (test == "ASIA") { return true; }
    if (test == "EUROPE") { return true; }
    if (test == "NORTH AMERICA") { return true; }
    if (test == "SOUTH AMERICA") { return true; }
    return false;
}

bool validateTestCenter(string test)
{
    for (int i = 0; i < test.length(); i++)
    {
        test[i] = toupper(test[i]);
    }

    if (test == "EUROPE") { return true; }
    if (test == "NONEUROPE") { return true; }
    return false;
}

bool validatePartType(string test)
{
    //msg = "Please select a type of part: \n*)Engine\n*)Chassis\n*)Electronics\n*)Aerodynamics\n";
    for (int i = 0; i < test.length(); i++)
    {
        test[i] = toupper(test[i]);
    }

    if (test == "AERODYNAMIC") { return true; }
    if (test == "CHASSIS") { return true; }
    if (test == "ELECTRONICs") { return true; }
    if (test == "ENGINE") { return true; }
    return false;

}

void ReRunTest(string TestName, TestingCenter* TC)
{
    string msg;
    string typetest = "";
    msg = "Please select the type of test: \n*)Windtunnel\n*)Software\n";

    while ((typetest != "WINDTUNNEL") && (typetest != "SOFTWARE"))
    {
        typetest = Get(msg);
        for (int i = 0; i < typetest.length(); i++)
        {
            typetest[i] = toupper(typetest[i]);
        }
    }

    Memento* m = TC->createMemento();
    if (typetest == "WINDTUNNEL")
    {
        TC->TestParts(true, TestName);
        cout <<endl<< wc->getTestsLeft() << " Windtunnel tests left";
    }
    else
    {
        TC->TestParts(false, TestName);
    }

    cout << endl;

    string print = Get("Do you want to rerun the test? (Y/N)");
    print[0] = toupper(print[0]);
    if (print != "Y")
    {
        return;
    }

    string reinstate = Get("Do you want to reinstate original parts? (Y/N)");
    reinstate[0] = toupper(reinstate[0]);
    if (reinstate == "Y")
    {
        TC->setMemento(m);
        return ReRunTest(TestName, TC);
    }
    else
    {
        return TestingCenterTest();
    }
}