//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_CHASSISFACTORY_H
#define BENETTON_F1_CHASSISFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/ChassisPart.h"

class ChassisFactory: public PartsFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Superclass for Chassis parts factories
     */
    friend class Chassis;
public:
    ChassisFactory();
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type) = 0;
    /**
     *
     * @param newDef : the new part to set as default prototype for the factories
     */
    void setDefault(Part* newDef);
protected:
    ChassisPart* defaultChassis;
};


#endif //BENETTON_F1_CHASSISFACTORY_H
