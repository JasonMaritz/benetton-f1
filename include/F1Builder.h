//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1BUILDER_H
#define BENETTON_F1_F1BUILDER_H

#include "F1Car.h"

class F1Builder {
public:
    F1Car* getResult();
    void buildPart(Part* carPart);
};

#endif //BENETTON_F1_F1BUILDER_H
