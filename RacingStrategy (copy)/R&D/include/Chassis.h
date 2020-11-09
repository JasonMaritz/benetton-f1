//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_CHASSIS_H
#define BENETTON_F1_CHASSIS_H

#include "ResearchAndDevelopmentDepartment.h"
#include "../../PartsFactory/include/ChassisFactory.h"


class Chassis: public ResearchAndDevelopmentDepartment{
public:
    Chassis();
    Part* makePart(std::string type) override;
    Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) override;
    void setBest(Part* newBest);
    void developParts() override;
};

#endif //BENETTON_F1_CHASSIS_H
