#include <iostream>
#include "Strategy/RacingStrategyInterface.h"
#include "Container/LowPriority.h"
#include "Track/Track.h"
#include "Track/africa.h"
#include "Shipping/Shipper.h"
#include "RaceWeekend/RaceWeekendInterface.h"

using namespace std;

void testLowPriority();
RacingStrategyInterface* makeStrategy();

int main()
{
    //testLowPriority();

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

    auto* raceWeekendInterface = new RaceWeekendInterface("test", track);

    cout << rci->getStrategy() << endl;

    return 0;
}

void testLowPriority()
{
    cout << "Routes for low priority containers (each line a new set of containers):\n";
    LowPriority lp;
    lp.destinationsFromtxt("RacingStrategy (copy)/Data/Destinations.txt");
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
