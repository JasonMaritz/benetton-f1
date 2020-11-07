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
