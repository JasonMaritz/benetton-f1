//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEERING_H
#define BENETTON_F1_ENGINEERING_H

#include "ResearchAndDevelopmentDepartment.h"
#include "Engine.h"
#include "Chassis.h"
#include "Electronics.h"
#include "Aerodynamics.h"

class Engineering {
public:
    static Engineering* getInstance();
    void setBudget(double budget){this->budget = budget;};
    void setBest(Part* newBest);
    void develop();
    Engine* getEngine(){return engine;};
    Chassis* getChassis(){return chassis;};
    Electronics* getElectronics(){return electronics;};
    Aerodynamics* getAreodynamics(){return aerodynamics;};
protected:
    Engineering();
private:
    Engine* engine;
    Chassis* chassis;
    Electronics* electronics;
    Aerodynamics* aerodynamics;
    double budget;
    static Engineering* instance;
};

#endif //BENETTON_F1_ENGINEERING_H
