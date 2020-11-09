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
    /// Function to make a new soft tyre
    /// @returns A soft tyre object
    Tyre* make() override;
    ///Function to get the current performance of the tyre
    /// @returns A double value representing the current tyre performance
    double getPerformance() override;
};


#endif //RACINGSTRATEGY_SOFTTYRE_H
