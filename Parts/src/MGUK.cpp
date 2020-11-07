//
// Created by jason on 2020/11/06.
//

#include "../include/MGUK.h"

Part *MGUK::clone() {
    MGUK* nMGUK = new MGUK();
    nMGUK->efficiency = this->efficiency;
    nMGUK->powerDraw = this->powerDraw;
    nMGUK->powerContribution = this->powerContribution;
    nMGUK->wear = this->wear;
    return dynamic_cast<Part*>(nMGUK);
}
