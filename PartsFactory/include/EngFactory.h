//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ENGFACTORY_H
#define COS214_ENGFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "EngineFactory.h"

class EngFactory: public EngineFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ENGFACTORY_H
