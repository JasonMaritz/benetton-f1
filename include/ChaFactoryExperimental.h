//
// Created by jason on 2020/11/06.
//

#ifndef COS214_CHAFACTORYEXPERIMENTAL_H
#define COS214_CHAFACTORYEXPERIMENTAL_H

#include <string>
#include "Part.h"

class ChaFactoryExperimental {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_CHAFACTORYEXPERIMENTAL_H
