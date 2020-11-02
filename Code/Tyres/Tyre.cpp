//
// Created by chrissi-boi on 2020/11/02.
//

#include "Tyre.h"

string Tyre::getType()
{
    return this->type;
}

int Tyre::getWear()
{
    return this->wear;
}

int Tyre::getTemp()
{
    return  this->temp;
}

void Tyre::setType(string type)
{
    this->type = type;
}

void Tyre::setWear(int wear)
{
    this->wear = wear;
}

void Tyre::setTemp(int temp)
{
    this->temp = temp;
}

