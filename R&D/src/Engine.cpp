//
// Created by jason on 2020/11/03.
//

#include "../include/Engine.h"
#include "../../PartsFactory/include/EngFactory.h"
#include "../../PartsFactory/include/EngFactoryExperimental.h"

Engine::Engine() {
    myFactory = new EngFactory();
    myFactoryExperimental = new EngFactoryExperimental;
}

Part *Engine::makePart(std::string type) {
    return myFactory->produce(type);
}

Part *Engine::makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) {
    Part* p = myFactory->produce(type);
    p->mutatePD(pdraw);
    p->mutatePC(pcontrib);
    p->mutateEf(efficiency);
    return  p;
}

void Engine::setBest(Part *newBest) {
    myFactory->setDefault(newBest);
}

void Engine::developParts() {
    int r = rand()%2;
    switch (r){
        case 1:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("turbocharger"));
            break;
        case 2:
            experimentalParts.insert(experimentalParts.end(), myFactoryExperimental->produce("ice"));
            break;
    }
}
