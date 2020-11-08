#include <iostream>
#include "Strategy/RacingStrategyInterface.h"

using namespace std;

int main()
{
    auto* rci = new RacingStrategyInterface();

    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addHardTyre();
    rci->addBargeBoard(5,6,7);
    rci->addIce(6,7,7);
    rci->addChasis(4,4,4);
    rci->addDrs(3,3,3);
    rci->addMguh(2,2,2);
    rci->addMguk(1,1,1);
    rci->addEngergyStore(8,8,8);
    rci->addTurboCharger(9,9,9);
    rci->addName("Test");
    rci->addSoftTyre();

    ContainerSet* con = rci->buildAndGetContainerSet();

    cout << rci->getStrategy() << endl;

    return 0;
}
