//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ICE_H
#define COS214_ICE_H


#include "Part.h"

class ICE: public Part {
public:
    ICE(){type="ice";};
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_ICE_H
