//
// Created by chrissi-boi on 2020/11/02.
//

#include "SoftTyre.h"

Tyre *SoftTyre::make()
{
    this->setType("Soft");
    return this;
}

double SoftTyre::getPerformance()
{
    double data = 0;
    if(this->getTemp() < 100)
    {
        int w = this->getWear();
        if(w > 5)
        {
            w /= 2;
        }
        data = w/10.0;
    }
    else
    {
        int w = this->getWear();
        if(w < 5)
        {
            w *= 2;
        }
        data = w/10.0;
    }
    return data;
}
