//
// Created by jason on 2020/11/06.
//

#include "../include/DRS.h"

Part *DRS::clone() {
    DRS* nDRS = new DRS();
    nDRS->efficiency = this->efficiency;
    nDRS->powerDraw = this->powerDraw;
    nDRS->powerContribution = this->powerContribution;
    nDRS->wear = this->wear;
    return (Part *)(nDRS);
}

double DRS::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 30;
    temp += 15*powerContribution;
    temp += 55*efficiency;
    temp -= 30*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;}
