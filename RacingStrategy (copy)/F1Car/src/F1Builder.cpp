//
// Created by jason on 2020/11/03.
//

#include "../include/F1Builder.h"
#include "../../R&D/include/Engineering.h"
#include <sstream>

F1Builder::F1Builder() {
    result = new F1Car();
}

F1Car *F1Builder::getResult() {
    //add the correct missing parts
    Engineering* eng = Engineering::getInstance();
    if(!result->bargeboard){
        result->bargeboard = (Bargeboard *)(eng->getAreodynamics()->makePart("bargeboard"));
    }
    if (!result->drs){
        result->drs = (DRS *)(eng->getAreodynamics()->makePart("drs"));
    }
    if (!result->ice){
        result->ice = (ICE *)(eng->getEngine()->makePart("ice"));
    }
    if (!result->turboCharger){
        result->turboCharger = (TurboCharger *)(eng->getEngine()->makePart("turbo"));
    }
    if (!result->chassisPart){
        result->chassisPart = (ChassisPart *)(eng->getChassis()->makePart("chassis"));
    }
    if (!result->ers){
        result->ers = (ERS *)(eng->getElectronics()->makePart("ers"));
    }
    if (!result->mguh){
        result->mguh = (MGUH *)(eng->getElectronics()->makePart("mguh"));
    }
    if (!result->mguk){
        result->mguk = (MGUK *)(eng->getElectronics()->makePart("mguk"));
    }
    if (!result->energyStore){
        result->energyStore = (EnergyStore *)(eng->getElectronics()->makePart("energystore"));
    }
    return result;
}

void F1Builder::buildPart(Part *carPart)
{
    if(carPart == nullptr)
    {
        return;
    }

    std::string temp = carPart->getType();
    std::stringstream ss(temp);
    std::string t;
    getline(ss, t, ' ');
    if(t == "bargeboard")
    {
        delete result->bargeboard;
        result->bargeboard = (Bargeboard *)(carPart->clone());
    }else if (t == "drs"){
        delete result->drs;
        result->drs = (DRS*)(carPart->clone());
    }else if (t == "ice"){
        delete result->ice;
        result->ice = (ICE *)(carPart->clone());
    }else if (t == "turbocharger"){
        delete result->turboCharger;
        result->turboCharger = (TurboCharger *)(carPart->clone());
    }else if (t == "chassis"){
        delete result->chassisPart;
        result->chassisPart = (ChassisPart *)(carPart->clone());
    }else if (t == "ers"){
        delete result->ers;
        result->ers = (ERS *)(carPart->clone());
    }else if (t == "mguh"){
        delete result->mguh;
        result->mguh = (MGUH *)(carPart->clone());
    }else if (t == "mguk"){
        delete result->mguk;
        result->mguk = (MGUK *)(carPart->clone());
    }else if (t == "energystore"){
        delete result->energyStore;
        result->energyStore = (EnergyStore *)(carPart->clone());
    }
}

void F1Builder::reset()
{
    result = new F1Car;
}
