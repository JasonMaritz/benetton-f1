//
// Created by jason on 2020/11/03.
//

#include "../include/ResearchAndDevelopmentDepartment.h"


ResearchAndDevelopmentDepartment::~ResearchAndDevelopmentDepartment() {
    experimentalParts.clear();
    delete myFactoryExperimental;
    delete myFactory;
}
