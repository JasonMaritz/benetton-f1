//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ELECTRONICSPART_H
#define BENETTON_F1_ELECTRONICSPART_H

#include "Part.h"

class ElectronicsPart: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief ElectronicsPart abstract class
     */
public:
    ElectronicsPart();
    virtual double getPerformance() = 0;
    virtual Part* clone() = 0;
};


#endif //BENETTON_F1_ELECTRONICSPART_H
