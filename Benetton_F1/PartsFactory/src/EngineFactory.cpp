//
// Created by jason on 2020/11/03.
//

#include "../include/EngineFactory.h"
#include "../../Parts/include/ICE.h"
#include "../../Parts/include/TurboCharger.h"

EngineFactory::EngineFactory()
{
        //defaultICE = dynamic_cast<EnginePart*>(new ICE());
        defaultICE = (EnginePart *)(new ICE());
        defaultTurbo = (EnginePart *)(new TurboCharger());
}

void EngineFactory::setDefault(Part *newDef) {
    std::string t = newDef->getType();
    if (t == "ice")
        defaultICE = (EnginePart *)(newDef->clone());
    if(t == "turbocharger")
        defaultTurbo = (EnginePart *)(newDef->clone());
}
