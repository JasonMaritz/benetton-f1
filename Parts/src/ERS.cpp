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
    return dynamic_cast<Part*>(nERS);
}
