//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_AEROFACTORY_H
#define BENETTON_F1_AEROFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/AeroPart.h"

class AeroFactory: public PartsFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Superclass for aero parts factories
     */
    friend class Engineering;
public:
    AeroFactory();
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
    AeroPart* defaultBargeboard;
    AeroPart* defaultDRS;
};


#endif //BENETTON_F1_AEROFACTORY_H
