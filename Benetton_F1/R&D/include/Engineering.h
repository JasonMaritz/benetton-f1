//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_ENGINEERING_H
#define BENETTON_F1_ENGINEERING_H

#include "ResearchAndDevelopmentDepartment.h"
#include "Engine.h"
#include "Chassis.h"
#include "Electronics.h"
#include "Aerodynamics.h"

class Engineering
{
    /**
     * @author Jason Maritz u19053292
     * @brief Singleton class to provide unified access to parts factory and develops parts for testing purposes
     */
public:
    /**
     *
     * @return instance of Engineering to fulfill the singleton design pattern
     */
    static Engineering* getInstance();
    /**
     *
     * @param budget the value to set the budget member to
     */
    void setBudget(double budget){this->budget = budget;};
    /**
     *
     * @param newBest set the default part in the correct factory depending on the type of the part
     */
    void setBest(Part* newBest);
    /**
     * @brief develops parts and populates the experimentalParts member for use in testing
     */
    void develop();
    /**
     *
     * @return the instance of Engine in the Engineering class used to unify access
     */
    Engine* getEngine(){return engine;};
    /**
     *
     * @return the instance of Chassis in the Engineering class used to unify access
     */
    Chassis* getChassis(){return chassis;};
    /**
     *
     * @return the instance of Electronics in the Engineering class used to unify access
     */
    Electronics* getElectronics(){return electronics;};
    /**
     *
     * @return the instance of Aerodynamics in the Engineering class used to unify access
     */
    Aerodynamics* getAreodynamics(){return aerodynamics;};
protected:
    Engineering();
private:
    Engine* engine;
    Chassis* chassis;
    Electronics* electronics;
    Aerodynamics* aerodynamics;
    double budget;
    static Engineering* instance;
};

#endif //BENETTON_F1_ENGINEERING_H
