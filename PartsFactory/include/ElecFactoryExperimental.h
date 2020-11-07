//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORYEXPERIMENTAL_H
#define COS214_ELECFACTORYEXPERIMENTAL_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ElecFactory.h"

class ElecFactoryExperimental: public ElecFactory {
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORYEXPERIMENTAL_H
