//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_AEROPART_H
#define BENETTON_F1_AEROPART_H

#include "Part.h"

class AeroPart: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief Aeropart abstract class
     */
public:
    AeroPart();
    virtual double getPerformance() = 0;
    virtual Part* clone() = 0;
};


#endif //BENETTON_F1_AEROPART_H
