//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORYEXPERIMENTAL_H
#define COS214_ELECFACTORYEXPERIMENTAL_H

#include <string>
#include "Part.h"

class ElecFactoryExperimental {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORYEXPERIMENTAL_H
