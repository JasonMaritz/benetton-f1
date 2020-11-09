//
// Created by chrissi-boi on 2020/11/02.
//

#include "TyreFactory.h"

string TyreFactory::getStrategy()
{
    string data;
    data += "T: " + this->tyre->getType() + "\n";
    if(this->component != nullptr)
    {
        data += this->component->getStrategy();
    }
    return data;
}

void TyreFactory::add(RacingStrategy *item)
{
    if(this->component != nullptr)
    {
        this->component->add(item);
    }
    else
    {
        this->component = item;
    }
}

void TyreFactory::setTyre(Tyre *newTyre)
{
    this->tyre = newTyre;
}
