//
// Created by jason on 2020/11/06.
//

#include <random>
#include "../include/ChaFactoryExperimental.h"

Part *ChaFactoryExperimental::produce(std::string type) {
    std::uniform_real_distribution<double> uniform(0,1);
    std::default_random_engine engineR;
    Part* res = ChaFactory::produce(type);
    if(res == nullptr)
        return nullptr;
    res->mutateEf(uniform(engineR));
    res->mutatePC(uniform(engineR));
    res->mutatePD(uniform(engineR));
    return res;
}
