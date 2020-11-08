//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTS_H
#define BENETTON_F1_PARTS_H

#include <string>
#include <cmath>
#include "../../Container/PackedItem.h"
#include "../../Simulation/Result.h"

class Part : public PackedItem
{
public:
    virtual double getPerformance() = 0;
    void setResult(Result* res){result = res;};
    void setTestingCenter(TestingCenter* tc) { TC = tc; };
    std::string getType();
    virtual Part* clone() = 0;
    void mutatePC(double mut)
    {
        double temp = mut;
        powerContributionMutValue = temp*10;
        powerContribution*=mut;
        mut-=floor(powerContribution);
    };
    void mutatePD(double mut)
    {
        double temp = mut;
        powerDrawMutValue = temp*10;
        powerDraw*=mut;
        mut-=floor(powerDraw);
    };
    void mutateEf(double mut)
    {
        double temp = mut;
        efficiencyMutValue = temp*10;
        efficiency*=mut;
        mut-=floor(efficiency);
    };
protected:
    std::string type;
    //TestingCenter* TC = nullptr;
    double wear;
    double powerContribution;
    double powerDraw;
    double efficiency;
    int powerContributionMutValue = -1;
    int powerDrawMutValue = -1;
    int efficiencyMutValue = -1;
    Result* result = nullptr;

    void mutate(double powerContributionMut, double efficiencyMut, double powerDrawMut);
};

#endif //BENETTON_F1_PARTS_H
