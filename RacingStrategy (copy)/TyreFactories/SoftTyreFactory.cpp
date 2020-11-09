//
// Created by chrissi-boi on 2020/11/02.
//

#include "SoftTyreFactory.h"
#include "../Tyres/SoftTyre.h"

SoftTyreFactory::SoftTyreFactory()
{
    Tyre* softTyre = new SoftTyre();
    this->setTyre(softTyre->make());
}

Tyre *SoftTyreFactory::makeTyre()
{
    Tyre* softTyre = new SoftTyre();
    return softTyre->make();
}
