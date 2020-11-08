//
// Created by jason on 2020/11/03.
//

#include "../include/ResearchAndDevelopmentDepartment.h"


string ResearchAndDevelopmentDepartment::getStrategy()
{
    string data;
    data += "P: " + this->part->getType() + "\n";
    if(this->component != nullptr)
    {
        data += this->component->getStrategy();
    }
    return data;
}

void ResearchAndDevelopmentDepartment::add(RacingStrategy *item)
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

void ResearchAndDevelopmentDepartment::setPart(Part *newPart)
{
    this->part = newPart;
}
