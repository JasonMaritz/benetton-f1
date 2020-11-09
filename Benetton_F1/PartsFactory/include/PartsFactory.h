//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_PARTSFACTORY_H
#define BENETTON_F1_PARTSFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"

class PartsFactory
{
    /**
     * @author Jason Maritz u19053292
     * @brief Parts Factory superclass to define a common interface
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the initialised part
     */
    virtual Part* produce(std::string type) = 0;
    /**
     *
     * @param newDef : new part to set default prototypes to in the factories
     */
    virtual void setDefault(Part* newDef) = 0;
};


#endif //BENETTON_F1_PARTSFACTORY_H
