//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINE_H
#define BENETTON_F1_ENGINE_H

#include "ResearchAndDevelopmentDepartment.h"

class Engine: public ResearchAndDevelopmentDepartment{
public:
    Engine();
    Part* makePart(std::string type);
    Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw);
    void setBest(Part* newBest);
    void developParts();
};

#endif //BENETTON_F1_ENGINE_H
