//
// Created by jason on 2020/11/06.
//

#ifndef COS214_AFACTORYEXPERIMENTAL_H
#define COS214_AFACTORYEXPERIMENTAL_H

#include <string>
#include "../../Parts/include/Part.h"
#include "AFactory.h"

class AFactoryExperimental: public AFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief aero parts factory to create experimental parts
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type);
};


#endif //COS214_AFACTORYEXPERIMENTAL_H
