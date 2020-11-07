//
// Created by jason on 2020/11/03.
//

#include "../include/TestBuilderDir.h"

TestBuilderDir::TestBuilderDir() {
    build = new F1Builder();
}

std::map<Part *, F1Car *> TestBuilderDir::buildCars(std::vector<Part *> parts) {
    std::map<Part *, F1Car *> temp;
    for(auto it = parts.begin(); it != parts.end(); it++){
        build->buildPart(*it);
        temp.insert(std::pair<Part*, F1Car*>((*it)->clone(), build->getResult()));
    }
    return temp;
}
