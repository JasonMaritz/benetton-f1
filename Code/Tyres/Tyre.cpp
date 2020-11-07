//
// Created by chrissi-boi on 2020/11/02.
//

#include "Tyre.h"

#include <utility>

string Tyre::getType()
{
    return this->type;
}

int Tyre::getWear() const
{
    return this->wear;
}

int Tyre::getTemp() const
{
    return  this->temp;
}

void Tyre::setType(string typeOfTyre)
{
    this->type = std::move(typeOfTyre);
}

void Tyre::setWear(int tyreWear)
{
    this->wear = tyreWear;
}

void Tyre::setTemp(int tyreTemp)
{
    this->temp = tyreTemp;
}

