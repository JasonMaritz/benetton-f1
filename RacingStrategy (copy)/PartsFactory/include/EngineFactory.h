//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEFACTORY_H
#define BENETTON_F1_ENGINEFACTORY_H

#include "PartsFactory.h"
#include "../../Parts/include/EnginePart.h"

class EngineFactory: public PartsFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Superclass for Engine parts factories
     */
    friend class Engine;
public:
    EngineFactory();
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type) = 0;
    /**
     *
     * @param newDef : the new part to set as default prototype for the factories
     */
    void setDefault(Part* newDef);
protected:
    EnginePart* defaultICE;
    EnginePart* defaultTurbo;
};


#endif //BENETTON_F1_ENGINEFACTORY_H
