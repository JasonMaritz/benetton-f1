//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORY_H
#define COS214_ELECFACTORY_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ElectronicsFactory.h"

class ElecFactory: public ElectronicsFactory{
    /**
     * @author Jason Maritz u19053292
     * @brief Electronics parts factory to create default parts
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORY_H
