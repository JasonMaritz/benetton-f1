//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ELECTRONICSFACTORY_H
#define BENETTON_F1_ELECTRONICSFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/ElectronicsPart.h"

class ElectronicsFactory: public PartsFactory {
    friend class Electronics;
public:
    ElectronicsFactory();
    virtual Part* produce(std::string type) = 0;
    void setDefault(Part* newDef);
protected:
    ElectronicsPart* defaultERS;
    ElectronicsPart* defaultMGUH;
    ElectronicsPart* defaultMGUK;
    ElectronicsPart* defaultEnergyStore;
};


#endif //BENETTON_F1_ELECTRONICSFACTORY_H
