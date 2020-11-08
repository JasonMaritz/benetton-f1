//
// Created by jason on 2020/11/03.
//

#include "../include/Aerodynamics.h"
#include "../../PartsFactory/include/AFactoryExperimental.h"

Aerodynamics::Aerodynamics() {
    myFactory = new AFactory();
    myFactoryExperimental = new AFactoryExperimental();
}

Part *Aerodynamics::makePart(std::string type) {
    return myFactory->produce(type);
}

Part *Aerodynamics::makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) {
    Part* p = myFactory->produce(type);
    p->mutatePD(pdraw);
    p->mutatePC(pcontrib);
    p->mutateEf(efficiency);
    return  p;
}

void Aerodynamics::setBest(Part *newBest) {
    myFactory->setDefault(newBest);
}

void Aerodynamics::developParts() {
    int r = rand()%2;
    switch (r){
        case 1:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("drs"));
            break;
        case 2:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("bargeboard"));
            break;
    }
}
