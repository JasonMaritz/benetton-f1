//
// Created by jason on 2020/11/06.
//

#ifndef COS214_MGUH_H
#define COS214_MGUH_H


#include "Part.h"

class MGUH: public Part {
public:
    MGUH(){type = "mguh";};
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_MGUH_H
