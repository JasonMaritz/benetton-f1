//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTS_H
#define BENETTON_F1_PARTS_H

#include <string>
#include <cmath>
#include "../../Container/PackedItem.h"
#include "../../Simulation/Result.h"
#include "../../TestingCenter/TestingCenter.h"

class TestingCenter;

class Part : public PackedItem
{
/**
     * @author Jason Maritz u19053292
     * @brief Part superclass defining how parts should act
     */
public:
    virtual double getPerformance() = 0;
    /**
     *
     * @param res : set the result member to the parameter provided
     */
    void setResult(Result* res){result = res;};
    /**
     *
     * @param tc : set the TC member to the TestingCenter provided
     */
    void setTestingCenter(TestingCenter* tc) { TC = tc; };
    /**
     *
     * @return a string representing the type of the part
     */
    std::string getType();
    virtual Part* clone() = 0;
    /**
    * mutates the powerContribution member
    * @param mut : value to mutate by
     */
    void mutatePC(double mut)
    {
        double temp = mut;
        temp += 1;
        powerContribution*=mut;
        powerContribution-=floor(powerContribution);
    };
    /**
    * mutates the powerDraw member
    * @param mut : value to mutate by
     */
    void mutatePD(double mut)
    {
        double temp = mut;
        temp += 1;
        powerDraw*=mut;
        powerDraw-=floor(powerDraw);
    };
    /**
    * mutates the efficiency member
    * @param mut : value to mutate by
     */
    void mutateEf(double mut)
    {
        double temp = mut;
        temp += 1;
        efficiency*=mut;
        efficiency-=floor(efficiency);
    };
protected:
    std::string type;
    TestingCenter* TC = nullptr;
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
