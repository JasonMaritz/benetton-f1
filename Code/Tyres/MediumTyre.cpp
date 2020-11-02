//
// Created by chrissi-boi on 2020/11/02.
//

#include "MediumTyre.h"

Tyre *MediumTyre::make()
{
    this->setType("Medium");
    return this;
}

double MediumTyre::getPerformance()
{
    //TODO-DO the necessary calculation for tyre performance
    return 0;
}
