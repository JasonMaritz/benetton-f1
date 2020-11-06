//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORY_H
#define COS214_ELECFACTORY_H

#include <string>
#include "Part.h"

class ElecFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORY_H
