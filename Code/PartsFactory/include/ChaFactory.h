//
// Created by jason on 2020/11/06.
//

#ifndef COS214_CHAFACTORY_H
#define COS214_CHAFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ChassisFactory.h"

class ChaFactory: public ChassisFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_CHAFACTORY_H
