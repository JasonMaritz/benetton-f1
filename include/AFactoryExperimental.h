//
// Created by jason on 2020/11/06.
//

#ifndef COS214_AFACTORYEXPERIMENTAL_H
#define COS214_AFACTORYEXPERIMENTAL_H

#include <string>
#include "Part.h"
#include "AFactory.h"

class AFactoryExperimental: public AFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_AFACTORYEXPERIMENTAL_H
