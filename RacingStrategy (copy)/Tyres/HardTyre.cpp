//
// Created by chrissi-boi on 2020/11/02.
//

#include "HardTyre.h"

Tyre *HardTyre::make()
{
    this->setType("Hard");
    this->setWear(1);
    this->setTemp(150);
    return this;
}

double HardTyre::getPerformance()
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
