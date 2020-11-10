//
// Created by jason on 2020/11/06.
//

#ifndef COS214_MGUK_H
#define COS214_MGUK_H


#include "Part.h"

class MGUK: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief The mguk part class
     */
public:
    MGUK(){type = "mguk";};
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


#endif //COS214_MGUK_H
