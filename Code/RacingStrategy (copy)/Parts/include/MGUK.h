//
// Created by jason on 2020/11/06.
//

#ifndef COS214_MGUK_H
#define COS214_MGUK_H


#include "Part.h"

class MGUK: public Part {
public:
    MGUK(){type = "mguk";};
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_MGUK_H
