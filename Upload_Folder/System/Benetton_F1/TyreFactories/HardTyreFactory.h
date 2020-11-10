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
    /// @returns A hard tyre object after its been made.
    Tyre* makeTyre() override;
};


#endif //RACINGSTRATEGY_HARDTYREFACTORY_H
