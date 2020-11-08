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
    rci->addIce();
    rci->addName("Test");
    rci->addSoftTyre();

    ContainerSet* con = rci->buildAndGetContainerSet();

    cout << rci->getStrategy() << endl;

    return 0;
}
