//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTS_H
#define BENETTON_F1_PARTS_H

#include <string>

class Part: public PackedItem{
public:
    virtual double getPerformance() = 0;
    void setResult(Result* res);
    void mutate(double powerContributionMut, double efficiencyMut, double powerDrawMut);
    double WindTunnelTest(int WTSpeed);
    double SoftwareTest(int timeSpeed);
    std::string getType();
private:
    std::string type;
    TestingCenter* TC;
    double wear;
    double powerContribution;
    double powerDraw;
    double efficiency;
    Result* result;
};

#endif //BENETTON_F1_PARTS_H
