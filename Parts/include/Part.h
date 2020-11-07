//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTS_H
#define BENETTON_F1_PARTS_H

#include <string>

class Part: public PackedItem{
public:
    virtual double getPerformance() = 0;
    void setResult(Result* res){result = res;};
    void mutate(double powerContributionMut, double efficiencyMut, double powerDrawMut);
    double WindTunnelTest(int WTSpeed);
    double SoftwareTest(int timeSpeed);
    std::string getType(){return type;};
    virtual Part* clone() = 0;
protected:
    std::string type;
    TestingCenter* TC = nullptr;
    double wear;
    double powerContribution;
    double powerDraw;
    double efficiency;
    Result* result = nullptr;
};

#endif //BENETTON_F1_PARTS_H
