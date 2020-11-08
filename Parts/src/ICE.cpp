//
// Created by jason on 2020/11/06.
//

#include "../include/ICE.h"

Part *ICE::clone() {
    ICE* nICE = new ICE();
    nICE->efficiency = this->efficiency;
    nICE->powerDraw = this->powerDraw;
    nICE->powerContribution = this->powerContribution;
    nICE->wear = this->wear;
    return dynamic_cast<Part*>(nICE);
}

double ICE::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 20;
    temp += 20*powerContribution;
    temp += 60*efficiency;
    temp -= 20*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;
}
