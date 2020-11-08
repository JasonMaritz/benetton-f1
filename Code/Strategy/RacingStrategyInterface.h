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
    Result* result{};

public:
    RacingStrategyInterface();
    void addSoftTyre();
    void addMediumTyre();
    void addHardTyre();
    void addName(string name);
    void addIce(double efficiency, double pcontrib, double pdraw);
    void addTurboCharger(double efficiency, double pcontrib, double pdraw);
    void addMguk(double efficiency, double pcontrib, double pdraw);
    void addMguh(double efficiency, double pcontrib, double pdraw);
    void addEngergyStore(double efficiency, double pcontrib, double pdraw);
    void addErs(double efficiency, double pcontrib, double pdraw);
    void addChasis(double efficiency, double pcontrib, double pdraw);
    void addDrs(double efficiency, double pcontrib, double pdraw);
    void addBargeBoard(double efficiency, double pcontrib, double pdraw);
    ContainerSet* buildAndGetContainerSet();
    string getStrategy();
    void setResult(Result* newResult);
    void generateReport();
};


#endif //RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
