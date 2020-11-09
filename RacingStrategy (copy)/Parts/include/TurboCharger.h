//
// Created by jason on 2020/11/06.
//

#ifndef COS214_TURBOCHARGER_H
#define COS214_TURBOCHARGER_H


#include "Part.h"

class TurboCharger: public Part {
    /**
     * @author Jason Maritz u19053292
     * @brief The turboCharger part class
     */
public:
    TurboCharger(){type="turbocharger";};
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


#endif //COS214_TURBOCHARGER_H
