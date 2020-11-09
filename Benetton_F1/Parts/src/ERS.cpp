//
// Created by jason on 2020/11/06.
//

#include "../include/ERS.h"

Part *ERS::clone() {
    ERS* nERS = new ERS();
    nERS->efficiency = this->efficiency;
    nERS->powerDraw = this->powerDraw;
    nERS->powerContribution = this->powerContribution;
    nERS->wear = this->wear;
    return (Part *)(nERS);
}

double ERS::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 25;
    temp += 36*powerContribution;
    temp += 39*efficiency;
    temp -= 25*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;
}
