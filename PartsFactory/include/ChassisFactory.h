//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_CHASSISFACTORY_H
#define BENETTON_F1_CHASSISFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/ChassisPart.h"

class ChassisFactory: public PartsFactory {
    friend class Chassis;
public:
    ~ChassisFactory();
    ChassisFactory();
    virtual Part* produce(std::string type) = 0;
    void setDefault(Part* newDef);
protected:
    static ChassisPart* defaultChassis;
};


#endif //BENETTON_F1_CHASSISFACTORY_H
