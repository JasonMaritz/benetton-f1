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
    return dynamic_cast<Part*>(nDRS);
}
