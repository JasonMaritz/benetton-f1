//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ELECTRONICSFACTORY_H
#define BENETTON_F1_ELECTRONICSFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/ElectronicsPart.h"

class ElectronicsFactory: public PartsFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Superclass for Electronics parts factories
     */
    friend class Electronics;
public:
    ElectronicsFactory();
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
    ElectronicsPart* defaultERS;
    ElectronicsPart* defaultMGUH;
    ElectronicsPart* defaultMGUK;
    ElectronicsPart* defaultEnergyStore;
};


#endif //BENETTON_F1_ELECTRONICSFACTORY_H
