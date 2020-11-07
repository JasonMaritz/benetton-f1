//
// Created by jason on 2020/11/06.
//

#ifndef COS214_AFACTORY_H
#define COS214_AFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "AeroFactory.h"

class AFactory: public AeroFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_AFACTORY_H
