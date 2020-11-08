//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_SOFTTYREFACTORY_H
#define RACINGSTRATEGY_SOFTTYREFACTORY_H


#include "TyreFactory.h"

class SoftTyreFactory : public TyreFactory
{
    Tyre* makeTyre() override;

public:
    SoftTyreFactory();
};


#endif //RACINGSTRATEGY_SOFTTYREFACTORY_H
