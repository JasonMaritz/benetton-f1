//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_TESTBUILDERDIR_H
#define BENETTON_F1_TESTBUILDERDIR_H

#include <map>
#include <vector>
#include "F1Car.h"
#include "F1Builder.h"

class TestBuilderDir{
public:
    TestBuilderDir();
    ~TestBuilderDir(){delete build;};
    std::map<Part*,F1Car*> buildCars(std::vector<Part*> parts);
private:
    F1Builder* build;
};


#endif //BENETTON_F1_TESTBUILDERDIR_H
