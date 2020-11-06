//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEFACTORY_H
#define BENETTON_F1_ENGINEFACTORY_H

#include "PartsFactory.h"
#include "EnginePart.h"

class EngineFactory: public PartsFactory {
    friend class Engine;
public:
    EngineFactory();
    virtual Part* produce(std::string type) = 0;
private:
    static EnginePart* defaultICE;
    static EnginePart* defaultTurbo;
};


#endif //BENETTON_F1_ENGINEFACTORY_H
