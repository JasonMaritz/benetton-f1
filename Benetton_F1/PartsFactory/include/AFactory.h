//
// Created by jason on 2020/11/06.
//

#ifndef COS214_AFACTORY_H
#define COS214_AFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "AeroFactory.h"

class AFactory: public AeroFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief aero parts factory to create default parts
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type);
};


#endif //COS214_AFACTORY_H
