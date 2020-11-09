//
// Created by jason on 2020/11/06.
//

#include "../include/ChassisPart.h"

ChassisPart::ChassisPart() {
    wear = 1;
    powerContribution = 0.5;
    powerDraw = 0.5;
    efficiency = 0.5;
    type = "chassis";
}

Part *ChassisPart::clone() {
    ChassisPart* nChassis = new ChassisPart();
    nChassis->efficiency = this->efficiency;
    nChassis->powerDraw = this->powerDraw;
    nChassis->powerContribution = this->powerContribution;
    nChassis->wear = this->wear;
    return (Part *)(nChassis);
}

double ChassisPart::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 5;
    temp += 35*powerContribution;
    temp += 60*efficiency;
    temp -= 5*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;
}
