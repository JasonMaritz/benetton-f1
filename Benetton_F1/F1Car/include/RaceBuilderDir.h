//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_RACEBUILDERDIR_H
#define BENETTON_F1_RACEBUILDERDIR_H

#include <vector>
#include "F1Car.h"
#include "F1Builder.h"

class RaceBuilderDir
{
    /**
 * @author Jason Maritz u19053292
 * @brief Class responsible for creating cars for the race as well as the simulator
 */
public:
    RaceBuilderDir();
    /**
     * @param parts, List of parts to build the car with
     * @return a completed F1Car built with F1Builder
     */
    F1Car* buildCar(std::vector<Part*> parts);
    /// resets the resulting F1Car
    void resetCar();
private:
    F1Builder* build;
};


#endif //BENETTON_F1_RACEBUILDERDIR_H
