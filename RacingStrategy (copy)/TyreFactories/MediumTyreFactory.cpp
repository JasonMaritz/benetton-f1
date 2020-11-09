//
// Created by chrissi-boi on 2020/11/02.
//

#include "MediumTyreFactory.h"
#include "../Tyres/MediumTyre.h"

MediumTyreFactory::MediumTyreFactory()
{
    Tyre* mediumTyre = new MediumTyre();
    this->setTyre(mediumTyre->make());
}

Tyre *MediumTyreFactory::makeTyre()
{
    Tyre* mediumTyre = new MediumTyre();
    return mediumTyre->make();
}
