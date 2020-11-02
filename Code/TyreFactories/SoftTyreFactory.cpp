//
// Created by chrissi-boi on 2020/11/02.
//

#include "SoftTyreFactory.h"
#include "../Tyres/SoftTyre.h"

Tyre *SoftTyreFactory::makeTyre()
{
    Tyre* softTyre = new SoftTyre();
    return softTyre->make();
}
