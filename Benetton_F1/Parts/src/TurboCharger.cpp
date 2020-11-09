//
// Created by jason on 2020/11/06.
//

#include "../include/TurboCharger.h"

Part *TurboCharger::clone() {
    TurboCharger* nTC = new TurboCharger();
    nTC->efficiency = this->efficiency;
    nTC->powerDraw = this->powerDraw;
    nTC->powerContribution = this->powerContribution;
    nTC->wear = this->wear;
    return (Part *)(nTC);
}

double TurboCharger::getPerformance() {
    if(wear == 0)
        return 0;
    double temp = 16;
    temp += 39*powerContribution;
    temp += 45*efficiency;
    temp -= 16*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    wear -= 0.1;
    return  temp;
}
