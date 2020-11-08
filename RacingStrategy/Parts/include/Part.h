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
    double WindTunnelTest(int WTSpeed);
    double SoftwareTest(int timeSpeed);
    std::string getType(){return type;};
    virtual Part* clone() = 0;
    void mutatePC(double mut){powerContribution*=mut;mut-=floor(powerContribution);};
    void mutatePD(double mut){powerDraw*=mut;mut-=floor(powerDraw);};
    void mutateEf(double mut){efficiency*=mut;mut-=floor(efficiency);};
protected:
    std::string type;
    //TestingCenter* TC = nullptr;
    double wear;
    double powerContribution;
    double powerDraw;
    double efficiency;
    Result* result = nullptr;

    void mutate(double powerContributionMut, double efficiencyMut, double powerDrawMut);
};

#endif //BENETTON_F1_PARTS_H
