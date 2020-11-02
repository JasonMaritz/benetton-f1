//
// Created by chrissi-boi on 2020/11/02.
//

#include "HardTyre.h"

Tyre *HardTyre::make()
{
    this->setType("Hard");
    return this;
}

double HardTyre::getPerformance()
{
    //TODO-DO the necessary calculation for tyre performance
    return 0;
}
