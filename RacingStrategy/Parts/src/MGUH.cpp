//
// Created by jason on 2020/11/06.
//

#include "../include/MGUH.h"

Part *MGUH::clone() {
    MGUH* nMGUH = new MGUH();
    nMGUH->efficiency = this->efficiency;
    nMGUH->powerDraw = this->powerDraw;
    nMGUH->powerContribution = this->powerContribution;
    nMGUH->wear = this->wear;
    return dynamic_cast<Part*>(nMGUH);
}

double MGUH::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 8;
    temp += 21*powerContribution;
    temp += 71*efficiency;
    temp -= 8*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;
}
