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
    Tyre* makeTyre() override;
};


#endif //RACINGSTRATEGY_MEDIUMTYREFACTORY_H
