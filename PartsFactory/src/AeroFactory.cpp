//
// Created by jason on 2020/11/03.
//

#include "../include/AeroFactory.h"
#include "../../Parts/include/Bargeboard.h"
#include "../../Parts/include/DRS.h"

AeroFactory::AeroFactory() {
    if(!defaultBargeboard)
        defaultBargeboard = dynamic_cast<AeroPart *>(new Bargeboard());
    if(!defaultDRS)
        defaultDRS = dynamic_cast<AeroPart*>(new DRS());
}

void AeroFactory::setDefault(Part *newDef) {
    std::string t = newDef->getType();
    if(t == "bargeboard")
        defaultBargeboard = dynamic_cast<AeroPart *>(newDef->clone());
    if(t == "drs")
        defaultDRS = dynamic_cast<AeroPart *>(newDef->clone());
}
