//
// Created by jason on 2020/11/06.
//

#include "../include/EngFactory.h"

Part *EngFactory::produce(std::string type) {
    if(type == "ice")
        return dynamic_cast<Part*>(defaultICE->clone());
    if(type == "turbocharger")
        return dynamic_cast<Part*>(defaultTurbo->clone());
}
