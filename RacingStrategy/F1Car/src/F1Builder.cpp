//
// Created by jason on 2020/11/03.
//

#include "../include/F1Builder.h"
#include "../../R&D/include/Engineering.h"

F1Builder::F1Builder() {
    result = new F1Car();
}

F1Car *F1Builder::getResult() {
    //add the correct missing parts
    Engineering* eng;
    if(!result->bargeboard){
        result->bargeboard = dynamic_cast<Bargeboard *>(eng->getAreodynamics()->makePart("bargeboard"));
    }
    if (!result->drs){
        result->drs = dynamic_cast<DRS *>(eng->getAreodynamics()->makePart("drs"));
    }
    if (!result->ice){
        result->ice = dynamic_cast<ICE *>(eng->getEngine()->makePart("ice"));
    }
    if (!result->turboCharger){
        result->turboCharger = dynamic_cast<TurboCharger *>(eng->getEngine()->makePart("turbo"));
    }
    if (!result->chassisPart){
        result->chassisPart = dynamic_cast<ChassisPart *>(eng->getChassis()->makePart("chassis"));
    }
    if (!result->ers){
        result->ers = dynamic_cast<ERS *>(eng->getElectronics()->makePart("ers"));
    }
    if (!result->mguh){
        result->mguh = dynamic_cast<MGUH *>(eng->getElectronics()->makePart("mguh"));
    }
    if (!result->mguk){
        result->mguk = dynamic_cast<MGUK *>(eng->getElectronics()->makePart("mguk"));
    }
    if (!result->energyStore){
        result->energyStore = dynamic_cast<EnergyStore *>(eng->getElectronics()->makePart("energystore"));
    }
    return result;
}

void F1Builder::buildPart(Part *carPart) {
    std::string t = carPart->getType();
    if(t == "Bargeboard"){
        delete result->bargeboard;
        result->bargeboard = dynamic_cast<Bargeboard *>(carPart->clone());
    }else if (t == "DRS"){
        delete result->drs;
        result->drs = dynamic_cast<DRS*>(carPart->clone());
    }else if (t == "ICE"){
        delete result->ice;
        result->ice = dynamic_cast<ICE *>(carPart->clone());
    }else if (t == "TurboCharger"){
        delete result->turboCharger;
        result->turboCharger = dynamic_cast<TurboCharger *>(carPart->clone());
    }else if (t == "Chassis"){
        delete result->chassisPart;
        result->chassisPart = dynamic_cast<ChassisPart *>(carPart->clone());
    }else if (t == "ERS"){
        delete result->ers;
        result->ers = dynamic_cast<ERS *>(carPart->clone());
    }else if (t == "MGUH"){
        delete result->mguh;
        result->mguh = dynamic_cast<MGUH *>(carPart->clone());
    }else if (t == "MGUK"){
        delete result->mguk;
        result->mguk = dynamic_cast<MGUK *>(carPart->clone());
    }else if (t == "EnergyStore"){
        delete result->energyStore;
        result->energyStore = dynamic_cast<EnergyStore *>(carPart->clone());
    }
}

void F1Builder::reset() {
    result = new F1Car;
}
