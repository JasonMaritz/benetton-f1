//
// Created by jason on 2020/11/06.
//

#ifndef COS214_DRS_H
#define COS214_DRS_H


#include "Part.h"
#include "AeroPart.h"

class DRS: public AeroPart {
public:
    DRS(){type = "drs";};
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_DRS_H
