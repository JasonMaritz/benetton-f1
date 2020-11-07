//
// Created by jason on 2020/11/06.
//

#include "../include/Bargeboard.h"

Part *Bargeboard::clone() {
    Bargeboard* nBBoard = new Bargeboard();
    nBBoard->efficiency = this->efficiency;
    nBBoard->powerDraw = this->powerDraw;
    nBBoard->powerContribution = this->powerContribution;
    nBBoard->wear = this->wear;
    return dynamic_cast<Part*>(nBBoard);
}

double Bargeboard::getPerformance() {
    double temp = 10;
    temp += 10*powerContribution;
    temp += 80*efficiency;
    temp -= 10*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    return  temp;
}
