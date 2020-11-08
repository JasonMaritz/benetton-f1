//
// Created by jason on 2020/11/06.
//

#include <random>
#include "../include/AFactoryExperimental.h"

Part *AFactoryExperimental::produce(std::string type) {
    std::uniform_real_distribution<double> uniform(0,1);
    std::default_random_engine engineR;
    Part* res = AFactory::produce(type);
    res->mutateEf(uniform(engineR));
    res->mutatePC(uniform(engineR));
    res->mutatePD(uniform(engineR));
    return res;
}
