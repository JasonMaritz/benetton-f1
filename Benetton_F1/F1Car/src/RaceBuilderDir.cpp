//
// Created by jason on 2020/11/03.
//

#include "../include/RaceBuilderDir.h"

F1Car *RaceBuilderDir::buildCar(std::vector<Part *> parts)
{
    for(auto & part : parts)
        build->buildPart(part);
    return build->getResult();
}

RaceBuilderDir::RaceBuilderDir()
{
    build = new F1Builder;
}

void RaceBuilderDir::resetCar()
{
    this->build->reset();
}
