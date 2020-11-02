//
// Created by chrissi-boi on 2020/11/02.
//

#include "MediumTyreFactory.h"
#include "../Tyres/MediumTyre.h"

Tyre *MediumTyreFactory::makeTyre()
{
    Tyre* mediumTyre = new MediumTyre();
    return mediumTyre->make();
}
