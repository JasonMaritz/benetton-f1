//
// Created by jason on 2020/11/03.
//

#include "../include/AeroFactory.h"
#include "../../Parts/include/Bargeboard.h"
#include "../../Parts/include/DRS.h"

AeroFactory::AeroFactory() {
        defaultBargeboard = (AeroPart *)(new Bargeboard());
        defaultDRS = (AeroPart *)(new DRS());
}

void AeroFactory::setDefault(Part *newDef) {
    std::string t = newDef->getType();
    if(t == "bargeboard")
        defaultBargeboard = (AeroPart *)(newDef->clone());
    if(t == "drs")
        defaultDRS = (AeroPart *)(newDef->clone());
}
