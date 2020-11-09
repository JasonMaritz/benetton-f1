//
// Created by jason on 2020/11/06.
//

#ifndef COS214_CHASSISPART_H
#define COS214_CHASSISPART_H


#include "Part.h"

class ChassisPart: public Part {
public:
    ChassisPart();
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_CHASSISPART_H
