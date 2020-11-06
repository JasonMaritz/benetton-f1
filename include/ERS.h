//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ERS_H
#define COS214_ERS_H


#include "Part.h"

class ERS: public Part {
public:
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_ERS_H
