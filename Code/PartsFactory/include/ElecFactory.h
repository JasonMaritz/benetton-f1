//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORY_H
#define COS214_ELECFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ElectronicsFactory.h"

class ElecFactory: public ElectronicsFactory{
public:
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORY_H
