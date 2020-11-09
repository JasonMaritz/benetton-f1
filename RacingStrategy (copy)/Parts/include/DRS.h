//
// Created by jason on 2020/11/06.
//

#ifndef COS214_DRS_H
#define COS214_DRS_H


#include "Part.h"
#include "AeroPart.h"

class DRS: public AeroPart
{
    /**
     * @author Jason Maritz u19053292
     * @brief The drs part class
     */
public:
    DRS(){type = "drs";};
    /**
     *
     * @return performance of the part based on the members
     */
    virtual double getPerformance();
    /**
     *
     * @return Part* cloned from the part it is called from
     */
    virtual Part* clone();
};


#endif //COS214_DRS_H
