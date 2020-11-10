//
// Created by jason on 2020/11/06.
//

#ifndef COS214_ELECFACTORYEXPERIMENTAL_H
#define COS214_ELECFACTORYEXPERIMENTAL_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ElecFactory.h"

class ElecFactoryExperimental: public ElecFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Electronic parts factory to create experimental parts
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type);
};


#endif //COS214_ELECFACTORYEXPERIMENTAL_H
