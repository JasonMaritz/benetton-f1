//
// Created by jason on 2020/11/03.
//

#include "../include/ElectronicsFactory.h"
#include "../../Parts/include/MGUH.h"
#include "../../Parts/include/EnergyStore.h"
#include "../../Parts/include/MGUK.h"
#include "../../Parts/include/ERS.h"

ElectronicsFactory::ElectronicsFactory() {

        defaultERS = (ElectronicsPart *)(new ERS());

        defaultEnergyStore = (ElectronicsPart *)(new EnergyStore());

        defaultMGUH = (ElectronicsPart *)(new MGUH());

        defaultMGUK = (ElectronicsPart *)(new MGUK());
}

void ElectronicsFactory::setDefault(Part *newDef) {
    std::string t = newDef->getType();
    if(t == "mguh")
        defaultMGUH = (ElectronicsPart *)(newDef->clone());
    if(t == "mguk")
        defaultMGUK = (ElectronicsPart *)(newDef->clone());
    if(t == "energystore")
        defaultEnergyStore = (ElectronicsPart *)(newDef->clone());
    if(t == "ers")
        defaultERS = (ElectronicsPart *)(newDef->clone());
}
