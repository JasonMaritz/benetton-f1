//
// Created by jason on 2020/11/06.
//

#ifndef COS214_DRS_H
#define COS214_DRS_H


#include "Part.h"

class DRS: public Part {
public:
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_DRS_H
