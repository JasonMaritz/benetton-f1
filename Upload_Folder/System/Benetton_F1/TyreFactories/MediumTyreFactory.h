//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_MEDIUMTYREFACTORY_H
#define RACINGSTRATEGY_MEDIUMTYREFACTORY_H


#include "TyreFactory.h"

class MediumTyreFactory : public TyreFactory
{
private:
public:
    MediumTyreFactory();
    /// @returns A medium tyre object after its been made.
    Tyre* makeTyre() override;
};


#endif //RACINGSTRATEGY_MEDIUMTYREFACTORY_H
