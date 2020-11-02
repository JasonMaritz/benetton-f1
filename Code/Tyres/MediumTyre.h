//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_MEDIUMTYRE_H
#define RACINGSTRATEGY_MEDIUMTYRE_H


#include "Tyre.h"

class MediumTyre : public Tyre
{
private:
public:
    Tyre* make() override;
    double getPerformance() override;
};


#endif //RACINGSTRATEGY_MEDIUMTYRE_H
