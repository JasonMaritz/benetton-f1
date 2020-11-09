//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_TESTBUILDERDIR_H
#define BENETTON_F1_TESTBUILDERDIR_H

#include <map>
#include <vector>
#include "F1Car.h"
#include "F1Builder.h"

class TestBuilderDir{
    /**
 * @author Jason Maritz u19053292
 * @brief Class responsible for creating cars for testing purposes
 */
public:
    TestBuilderDir();
    /**
     * @param parts, a Vector of parts to construct the cars from
     * @return a map of part* and F1Car* that map each car with a specific part to the part it was made with
     */
    std::map<Part*,F1Car*> buildCars(std::vector<Part*> parts);
private:
    F1Builder* build;
};


#endif //BENETTON_F1_TESTBUILDERDIR_H
