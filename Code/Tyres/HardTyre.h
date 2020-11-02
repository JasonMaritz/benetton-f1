//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_HARDTYRE_H
#define RACINGSTRATEGY_HARDTYRE_H


#include "Tyre.h"

class HardTyre : public Tyre
{
private:
public:
    Tyre* make() override;
    double getPerformance() override;
};


#endif //RACINGSTRATEGY_HARDTYRE_H
