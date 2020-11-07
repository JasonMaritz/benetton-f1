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
