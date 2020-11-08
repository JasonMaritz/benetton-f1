//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTSFACTORY_H
#define BENETTON_F1_PARTSFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"

class PartsFactory {
public:
    virtual Part* produce(std::string type) = 0;
    virtual void setDefault(Part* newDef) = 0;
};


#endif //BENETTON_F1_PARTSFACTORY_H
