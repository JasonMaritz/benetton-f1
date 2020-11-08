//
// Created by jason on 2020/11/06.
//

#include "../include/EngFactory.h"

Part *EngFactory::produce(std::string type)
{
    if(type == "ice")
    {
        return (Part *)(defaultICE->clone());
    }
    else if(type == "turbocharger")
    {
        return (Part *)(defaultTurbo->clone());
    }
}
