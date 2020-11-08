//
// Created by chrissi-boi on 2020/11/04.
//

#ifndef RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
#define RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H


#include "RacingStrategy.h"
#include "../Container/ContainerSet.h"
#include "../R&D/include/Engineering.h"
#include "../Simulation/Result.h"

class RacingStrategyInterface
{
private:
    Engineering* engineering;
    RacingStrategy* racingStrategy = nullptr;
    bool hasName = false;
    bool isFirst = true;
    int tyreCount = 0;
    Result* result;

public:
    RacingStrategyInterface();
    void addSoftTyre();
    void addMediumTyre();
    void addHardTyre();
    void addName(string name);
    void addIce();
    void addIceExperimental(double efficiency, double pcontrib, double pdraw);
    void addTurboCharger();
    void addTurboChargerExperimental(double efficiency, double pcontrib, double pdraw);
    void addMguk();
    void addMgukExperimental(double efficiency, double pcontrib, double pdraw);
    void addMguh();
    void addMguhExperimental(double efficiency, double pcontrib, double pdraw);
    void addEngergyStore();
    void addEngergyStoreExperimental(double efficiency, double pcontrib, double pdraw);
    void addErs();
    void addErsExperimental(double efficiency, double pcontrib, double pdraw);
    void addChasis();
    void addChasisExperimental(double efficiency, double pcontrib, double pdraw);
    void addDrs();
    void addDrsExperimental(double efficiency, double pcontrib, double pdraw);
    void addBargeBoard();
    void addBargeBoardExperimental(double efficiency, double pcontrib, double pdraw);
    ContainerSet* buildAndGetContainerSet();
    string getStrategy();
    void setResult(Result* newResult);
    void generateReport();
};


#endif //RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
