//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1BUILDER_H
#define BENETTON_F1_F1BUILDER_H

#include "F1Car.h"

class F1Builder {
    /**
     * @author Jason Maritz u19053292
     * @brief Class responsible for building a completed F1Car for use in other classes
     */
public:
    F1Builder();
    ///@return F1Car* , the completed car
    ///@brief also checks that if some part has not been built it adds a default one
    F1Car* getResult();
    ///@brief resets the builder to build another car
    void reset();
    ///@param carPart
    void buildPart(Part* carPart);
private:
    F1Car* result;
};




#endif //BENETTON_F1_F1BUILDER_H
