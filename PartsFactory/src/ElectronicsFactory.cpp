//
// Created by jason on 2020/11/03.
//

#include "../include/ElectronicsFactory.h"
#include "../../Parts/include/MGUH.h"
#include "../../Parts/include/EnergyStore.h"
#include "../../Parts/include/MGUK.h"
#include "../../Parts/include/ERS.h"

ElectronicsFactory::ElectronicsFactory() {
    if(!defaultERS)
        defaultERS = dynamic_cast<ElectronicsPart*>(new ERS());
    if(!defaultEnergyStore)
        defaultEnergyStore = dynamic_cast<ElectronicsPart*>(new EnergyStore());
    if(!defaultMGUH)
        defaultMGUH = dynamic_cast<ElectronicsPart*>(new MGUH());
    if(!defaultMGUK)
        defaultMGUK = dynamic_cast<ElectronicsPart*>(new MGUK());
}