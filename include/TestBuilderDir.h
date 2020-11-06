//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_TESTBUILDERDIR_H
#define BENETTON_F1_TESTBUILDERDIR_H

#include <map>
#include "F1Car.h"

static class TestBuilderDir{
    static std::map<Part*,F1Car*> buildCar(std::vector<Part*> parts);
};


#endif //BENETTON_F1_TESTBUILDERDIR_H
