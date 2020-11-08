//
// Created by jason on 2020/11/03.
//

#include "../include/ChassisFactory.h"
ChassisFactory::ChassisFactory() {
    if(!defaultChassis)
        defaultChassis = new ChassisPart();
}
void ChassisFactory::setDefault(Part *newDef) {
    defaultChassis = dynamic_cast<ChassisPart *>(newDef->clone());
}