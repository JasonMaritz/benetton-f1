//
// Created by jason on 2020/11/06.
//

#ifndef COS214_TURBOCHARGER_H
#define COS214_TURBOCHARGER_H


#include "Part.h"

class TurboCharger: public Part {
public:
    virtual double getPerformance();
    virtual Part* clone();
};


#endif //COS214_TURBOCHARGER_H
