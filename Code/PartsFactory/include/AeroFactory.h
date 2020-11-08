//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_AEROFACTORY_H
#define BENETTON_F1_AEROFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/AeroPart.h"

class AeroFactory: public PartsFactory {
    friend class Engineering;
public:
    AeroFactory();
    virtual Part* produce(std::string type) = 0;
    void setDefault(Part* newDef);
protected:
    AeroPart* defaultBargeboard;
    AeroPart* defaultDRS;
};


#endif //BENETTON_F1_AEROFACTORY_H
