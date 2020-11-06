//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ENGFACTORYEXPERIMENTAL_H
#define COS214_ENGFACTORYEXPERIMENTAL_H

#include <string>
#include "Part.h"
#include "EngFactory.h"

class EngFactoryExperimental: public EngFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ENGFACTORYEXPERIMENTAL_H
