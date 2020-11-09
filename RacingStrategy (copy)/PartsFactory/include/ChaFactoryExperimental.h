//
// Created by jason on 2020/11/06.
//

#ifndef COS214_CHAFACTORYEXPERIMENTAL_H
#define COS214_CHAFACTORYEXPERIMENTAL_H

#include <string>
#include "../../Parts/include/Part.h"
#include "ChaFactory.h"

class ChaFactoryExperimental: public ChaFactory {
    /**
     * @author Jason Maritz u19053292
     * @brief Chassis parts factory to create experimental parts
     */
public:
    /**
     *
     * @param type : type of part to produce
     * @return the instantiated part
     */
    virtual Part* produce(std::string type);
};


#endif //COS214_CHAFACTORYEXPERIMENTAL_H
