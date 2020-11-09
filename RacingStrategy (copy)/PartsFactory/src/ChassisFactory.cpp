//
// Created by jason on 2020/11/03.
//

#include "../include/ChassisFactory.h"
ChassisFactory::ChassisFactory() {
        defaultChassis = new ChassisPart();
}
void ChassisFactory::setDefault(Part *newDef) {
    defaultChassis = (ChassisPart *)(newDef->clone());
}