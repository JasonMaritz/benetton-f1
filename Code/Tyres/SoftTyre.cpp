//
// Created by chrissi-boi on 2020/11/02.
//

#include "SoftTyre.h"

Tyre *SoftTyre::make()
{
    this->setType("Soft");
    return this;
}

double SoftTyre::getPerformance()
{
    //TODO-DO the necessary calculation for tyre performance
    return 0;
}
