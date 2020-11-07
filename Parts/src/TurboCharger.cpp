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
    return dynamic_cast<Part*>(nTC);
}
