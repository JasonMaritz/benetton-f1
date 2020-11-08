//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_HARDTYREFACTORY_H
#define RACINGSTRATEGY_HARDTYREFACTORY_H


#include "TyreFactory.h"

class HardTyreFactory : public TyreFactory
{
private:
public:
    HardTyreFactory();
    Tyre* makeTyre() override;
};


#endif //RACINGSTRATEGY_HARDTYREFACTORY_H
