//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ENGFACTORY_H
#define COS214_ENGFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "EngineFactory.h"

class EngFactory : public EngineFactory
{
    /**
    * @author Jason Maritz u19053292
    * @brief Engine parts factory to create default parts
    */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type) override;
};


#endif //COS214_ENGFACTORY_H
