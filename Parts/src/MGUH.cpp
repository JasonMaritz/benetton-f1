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
