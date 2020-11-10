//
// Created by jason on 2020/11/06.
//

#ifndef COS214_MGUH_H
#define COS214_MGUH_H


#include "Part.h"

class MGUH: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief The mguh part class
     */
public:
    MGUH(){type = "mguh";};
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


#endif //COS214_MGUH_H
