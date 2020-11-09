//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_AERODYNAMICS_H
#define BENETTON_F1_AERODYNAMICS_H

#include "ResearchAndDevelopmentDepartment.h"

class Aerodynamics: public ResearchAndDevelopmentDepartment{
    /**
 * @author Jason Maritz u19053292
 * @brief Class responsible for developing and constructing Aerodynamic parts
 */
public:
    Aerodynamics();
    /**
     *
     * @param type : type of Aerodynamic part to make
     * @return part* : the instantiated part
     */
    Part* makePart(std::string type);
    /**
     *
     * @param type : type of Aerodynamic part to produce
     * @param efficiency : value to mutate efficiency member with
     * @param pcontrib : value to mutate powerContribution member with
     * @param pdraw : value to mutate powerDraw member with
     * @return the instantiated part
     */
    Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw);
    /**
     *
     * @param newBest : part to set the new default prototype in the factories
     */
    void setBest(Part* newBest);
    /**
     * @brief develops parts and populates the experimentalPartsVector for testing
     */
    void developParts();
};

#endif //BENETTON_F1_AERODYNAMICS_H
