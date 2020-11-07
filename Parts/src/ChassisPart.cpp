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
    return dynamic_cast<Part*>(nChassis);
}
