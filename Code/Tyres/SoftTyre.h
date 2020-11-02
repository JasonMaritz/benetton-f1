//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_SOFTTYRE_H
#define RACINGSTRATEGY_SOFTTYRE_H


#include "Tyre.h"

class SoftTyre : public Tyre
{
private:
public:
    Tyre* make() override;
    double getPerformance() override;
};


#endif //RACINGSTRATEGY_SOFTTYRE_H
