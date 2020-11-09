//
// Created by jason on 2020/11/06.
//

#include "../include/ElecFactory.h"

Part *ElecFactory::produce(std::string type)
{
    if(type == "mguk")
        return (Part *)(defaultMGUK->clone());
    if(type == "mguh")
        return (Part *)(defaultMGUH->clone());
    if(type == "energystore")
        return (Part *)(defaultEnergyStore->clone());
    if(type == "ers")
        return (Part *)(defaultERS->clone());
    return nullptr;
}
