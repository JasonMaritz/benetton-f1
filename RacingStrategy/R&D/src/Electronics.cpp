//
// Created by jason on 2020/11/03.
//

#include "../include/Electronics.h"
#include "../../PartsFactory/include/ElecFactoryExperimental.h"

Electronics::Electronics() {
    myFactory = new ElecFactory();
    myFactoryExperimental = new ElecFactoryExperimental();
}

Part *Electronics::makePart(std::string type) {
    return myFactory->produce(type);
}

Part *Electronics::makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) {
    Part* p = myFactory->produce(type);
    p->mutatePD(pdraw);
    p->mutatePC(pcontrib);
    p->mutateEf(efficiency);
    return  p;
}

void Electronics::setBest(Part *newBest) {
    myFactory->setDefault(newBest);
}

void Electronics::developParts() {
    int r = rand()%4;
    switch (r){
        case 1:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("mguh"));
            break;
        case 2:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("mguk"));
            break;
        case 3:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("energystore"));
            break;
        case 4:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("ers"));
            break;
    }
}
