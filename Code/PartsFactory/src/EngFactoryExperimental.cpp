//
// Created by jason on 2020/11/06.
//

#include <random>
#include "../include/EngFactoryExperimental.h"

Part *EngFactoryExperimental::produce(std::string type) {
    std::uniform_real_distribution<double> uniform(0,1);
    std::default_random_engine engineR;
    Part* res = EngFactory::produce(type);
    if(res == nullptr)
        return nullptr;
    res->mutateEf(uniform(engineR));
    res->mutatePC(uniform(engineR));
    res->mutatePD(uniform(engineR));
    return res;
}
