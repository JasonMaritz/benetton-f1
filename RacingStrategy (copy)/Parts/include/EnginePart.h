//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEPART_H
#define BENETTON_F1_ENGINEPART_H

#include "Part.h"

class EnginePart: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief EnginePart abstract class
     */
public:
    EnginePart();
    virtual double getPerformance() = 0;
    virtual Part* clone() = 0;
};


#endif //BENETTON_F1_ENGINEPART_H
