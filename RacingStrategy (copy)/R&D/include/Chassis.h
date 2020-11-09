//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_CHASSIS_H
#define BENETTON_F1_CHASSIS_H

#include "ResearchAndDevelopmentDepartment.h"
#include "../../PartsFactory/include/ChassisFactory.h"


class Chassis: public ResearchAndDevelopmentDepartment{
    /**
 * @author Jason Maritz u19053292
 * @brief Class responsible for developing and constructing Chassis parts
 */
public:
    Chassis();
    /**
     *
     * @param type : type of chassis part to make, required for inheritance
     * @return part* : the instantiated part
     */
    Part* makePart(std::string type) override;
    /**
     *
     * @param type : type of chassis part to produce
     * @param efficiency : value to mutate efficiency member with
     * @param pcontrib : value to mutate powerContribution member with
     * @param pdraw : value to mutate powerDraw member with
     * @return the instantiated part
     */
    Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) override;
    /**
     *
     * @param newBest : part to set the new default prototype in the factories
     */
    void setBest(Part* newBest);
    /**
     * @brief develops parts and populates the experimentalPartsVector for testing
     */
    void developParts() override;
};

#endif //BENETTON_F1_CHASSIS_H
