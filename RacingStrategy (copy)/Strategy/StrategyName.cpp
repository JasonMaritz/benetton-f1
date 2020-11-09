//
// Created by chrissi-boi on 2020/11/02.
//

#include "StrategyName.h"

StrategyName::StrategyName(string name)
{
    this->name = name;
}

void StrategyName::add(RacingStrategy *item)
{
    //Does nothing
}

string StrategyName::getStrategy()
{
    string data;
    data += "N: " + this->name + "\n";
    return data;
}


