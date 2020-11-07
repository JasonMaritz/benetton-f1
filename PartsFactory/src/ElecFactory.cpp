//
// Created by jason on 2020/11/06.
//

#include "../include/ElecFactory.h"

Part *ElecFactory::produce(std::string type) {
    if(type == "mguk")
        return dynamic_cast<Part*>(defaultMGUK->clone());
    if(type == "mguh")
        return dynamic_cast<Part*>(defaultMGUH->clone());
    if(type == "energystore")
        return dynamic_cast<Part*>(defaultEnergyStore->clone());
    if(type == "ers")
        return dynamic_cast<Part*>(defaultERS->clone());
}
