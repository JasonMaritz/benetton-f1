//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEPART_H
#define BENETTON_F1_ENGINEPART_H

#include "Part.h"

class EnginePart: public Part {
public:
    EnginePart();
    EnginePart(EnginePart* clone);
    virtual double getPerformance() = 0;
};


#endif //BENETTON_F1_ENGINEPART_H
