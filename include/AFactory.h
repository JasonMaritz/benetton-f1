//
// Created by jason on 2020/11/06.
//

#ifndef COS214_AFACTORY_H
#define COS214_AFACTORY_H

#include <string>
#include "Part.h"

class AFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_AFACTORY_H
