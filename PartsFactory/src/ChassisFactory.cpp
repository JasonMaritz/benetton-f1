//
// Created by jason on 2020/11/03.
//

#include "../include/ChassisFactory.h"
ChassisFactory::ChassisFactory() {
    if(!defaultChassis)
        defaultChassis = new ChassisPart();
}