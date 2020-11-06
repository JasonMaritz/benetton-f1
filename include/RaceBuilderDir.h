//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_RACEBUILDERDIR_H
#define BENETTON_F1_RACEBUILDERDIR_H

#include "F1Car.h"

static class RaceBuilderDir {
    static F1Car* buildCar(std::vector<Part*> parts);
};


#endif //BENETTON_F1_RACEBUILDERDIR_H
