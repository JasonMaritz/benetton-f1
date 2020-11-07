//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1BUILDER_H
#define BENETTON_F1_F1BUILDER_H

#include "F1Car.h"

class F1Builder {
public:
    F1Builder();
    F1Car* getResult();
    void reset();
    void buildPart(Part* carPart);
private:
    F1Car* result;
};




#endif //BENETTON_F1_F1BUILDER_H
