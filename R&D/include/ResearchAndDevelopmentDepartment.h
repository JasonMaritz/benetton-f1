//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H
#define BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H

#include <vector>
#include <string>
#include "../../Parts/include/Part.h"
#include "../../PartsFactory/include/PartsFactory.h"

class ResearchAndDevelopmentDepartment {
public:
    std::vector<Part*> getExperimentalParts(){std::vector<Part*> t = experimentalParts; experimentalParts.clear();return t;};
    virtual void developParts() = 0;
    virtual Part* makePart(std::string type) = 0;
    virtual Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) = 0;
protected:
    std::vector<Part*> experimentalParts;
    PartsFactory* myFactory;
    PartsFactory* myFactoryExperimental;
};


#endif //BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H
