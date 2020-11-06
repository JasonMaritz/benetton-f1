//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_AEROPART_H
#define BENETTON_F1_AEROPART_H

#include "Part.h"

class AeroPart: public Part {
public:
    AeroPart();
    AeroPart(AeroPart* clone);
    virtual double getPerformance() = 0;
};


#endif //BENETTON_F1_AEROPART_H
