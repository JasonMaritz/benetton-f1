//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_RACEBUILDERDIR_H
#define BENETTON_F1_RACEBUILDERDIR_H

#include <vector>
#include "F1Car.h"
#include "F1Builder.h"

class RaceBuilderDir {
public:
    RaceBuilderDir();
    ~RaceBuilderDir(){delete build;};
    F1Car* buildCar(std::vector<Part*> parts);
private:
    F1Builder* build;
};


#endif //BENETTON_F1_RACEBUILDERDIR_H
