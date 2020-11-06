//
// Created by jason on 2020/11/06.
//

#ifndef COS214_BARGEBOARD_H
#define COS214_BARGEBOARD_H


#include "Part.h"

class Bargeboard: public Part {
public:
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_BARGEBOARD_H
