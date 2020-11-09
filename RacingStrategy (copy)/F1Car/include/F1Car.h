//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1CAR_H
#define BENETTON_F1_F1CAR_H

#include "../../Parts/include/Bargeboard.h"
#include "../../Parts/include/DRS.h"
#include "../../Parts/include/ICE.h"
#include "../../Parts/include/TurboCharger.h"
#include "../../Parts/include/ChassisPart.h"
#include "../../Parts/include/ERS.h"
#include "../../Parts/include/MGUH.h"
#include "../../Parts/include/MGUK.h"
#include "../../Parts/include/EnergyStore.h"

class Result;

class F1Car {
/**
 * @author Jason Maritz u19053292
 * @brief F1Car, a container for all the parts with the needed functionality to get the performance thereof
 */
    friend class F1Builder;
public:
    ~F1Car();
    ///@return the average performance of the parts of the car
    double getPerformance();
    ///@param  result: the result pointer to set res equal to
    void setResult(Result* result){res = result;};
    ///@brief generates report for simulation
    void generateReport();
private:
    Result* res = nullptr;
    Bargeboard* bargeboard= nullptr;
    DRS* drs= nullptr;
    ICE* ice= nullptr;
    TurboCharger* turboCharger= nullptr;
    ChassisPart* chassisPart= nullptr;
    ERS* ers= nullptr;
    MGUH* mguh= nullptr;
    MGUK* mguk= nullptr;
    EnergyStore* energyStore= nullptr;

    std::vector<Part *> generateParts();
};

#endif //BENETTON_F1_F1CAR_H
