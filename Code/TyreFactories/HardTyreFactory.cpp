//
// Created by chrissi-boi on 2020/11/02.
//

#include "HardTyreFactory.h"
#include "../Tyres/HardTyre.h"

Tyre *HardTyreFactory::makeTyre()
{
    Tyre* hardTyre = new HardTyre();
    return hardTyre->make();
}
