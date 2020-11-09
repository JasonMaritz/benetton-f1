//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_SOFTTYREFACTORY_H
#define RACINGSTRATEGY_SOFTTYREFACTORY_H


#include "TyreFactory.h"

class SoftTyreFactory : public TyreFactory
{
public:
    SoftTyreFactory();
    /// @returns A soft tyre object after its been made.
    Tyre* makeTyre() override;
};


#endif //RACINGSTRATEGY_SOFTTYREFACTORY_H
