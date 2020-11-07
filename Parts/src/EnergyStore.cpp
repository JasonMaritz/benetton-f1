//
// Created by jason on 2020/11/06.
//

#include "../include/EnergyStore.h"

Part *EnergyStore::clone() {
    EnergyStore* nES = new EnergyStore();
    nES->efficiency = this->efficiency;
    nES->powerDraw = this->powerDraw;
    nES->powerContribution = this->powerContribution;
    nES->wear = this->wear;
    return dynamic_cast<Part*>(nES);
}

double EnergyStore::getPerformance() {
    double temp = 43;
    temp += 20*powerContribution;
    temp += 28*efficiency;
    temp -= 29*powerDraw;
    temp /= 100;
    temp -= 0.1*wear;
    return  temp;
}
