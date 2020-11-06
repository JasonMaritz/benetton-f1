//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEERING_H
#define BENETTON_F1_ENGINEERING_H

#include "ResearchAndDevelopmentDepartment.h"

class Engineering {
public:
    static Engineering* getInstance();
    void setBudget(double budget);
protected:
    Engineering();
private:
    std::vector<ResearchAndDevelopmentDepartment> departments;
    double budget;
    Engineering* instance;
};

#endif //BENETTON_F1_ENGINEERING_H
