//
// Created by jason on 2020/11/06.
//

#include "../include/AFactory.h"

Part *AFactory::produce(std::string type) {
    if(type == "drs")
        return (Part *)(defaultDRS->clone());
    if(type == "bargeboard")
        return (Part *)(defaultBargeboard->clone());
    return nullptr;
}
