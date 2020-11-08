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
    /// Default constructor used to get an instance on Engineering.
    RacingStrategyInterface();
    ///Function used to add a soft tyre to the current RacingStrategy.
    void addSoftTyre();
    ///Function used to add a medium tyre to the current RacingStrategy.
    void addMediumTyre();
    ///Function used to add a hard tyre to the current RacingStrategy.
    void addHardTyre();
    ///Function used to add a name to the current RacingStrategy.
    void addName(string name);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addIce(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addTurboCharger(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addMguk(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addMguh(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addEngergyStore(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addErs(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addChasis(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addDrs(double efficiency, double pcontrib, double pdraw);

    ///Function used to add a experimental Engine part referred to as "ice" to the current RacingStrategy.
    /// @param efficiency This is a integer value between 1 and 10 (inclusive) used to mutate the the parts efficiency.
    /// @param pcontrib This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power contribution.
    /// @param pdraw This is a integer value between 1 and 10 (inclusive) used to mutate the the parts power draw.
    void addBargeBoard(double efficiency, double pcontrib, double pdraw);

    /// Function used to build and populate the container set with the tyres and parts needed for shipping.
    ///@returns A ContainerSet object holding all the parts used in the strategy.
    ContainerSet* buildAndGetContainerSet();

    ///Function used to get a list of all the objects part of the current RacingStrategy.
    /// @returns A string holding a list of all the objects in the current RacingStrategy.
    string getStrategy();

    ///Function used to set the value of result based on the results of the simulation.
    ///@param newResult A Result object holding the data of a simulation
    void setResult(Result* newResult);

    ///Function used to populate the racing strategy report of the Result object
    void generateReport();
};


#endif //RACINGSTRATEGY_RACINGSTRATEGYINTERFACE_H
