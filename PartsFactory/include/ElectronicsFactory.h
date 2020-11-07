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
private:
    static ElectronicsPart* defaultERS;
    static ElectronicsPart* defaultMGUH;
    static ElectronicsPart* defaultMGUK;
    static ElectronicsPart* defaultEnergyStore;
};


#endif //BENETTON_F1_ELECTRONICSFACTORY_H
