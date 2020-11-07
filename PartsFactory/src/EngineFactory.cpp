//
// Created by jason on 2020/11/03.
//

#include "../include/EngineFactory.h"
#include "../../Parts/include/ICE.h"
#include "../../Parts/include/TurboCharger.h"

EngineFactory::EngineFactory() {
    if(!defaultICE)
        defaultICE = dynamic_cast<EnginePart*>(new ICE());
    if(!defaultTurbo)
        defaultTurbo = dynamic_cast<EnginePart*>(new TurboCharger());
}