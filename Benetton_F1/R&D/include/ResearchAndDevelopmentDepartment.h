//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H
#define BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H

#include <vector>
#include <string>
#include "../../Parts/include/Part.h"
#include "../../PartsFactory/include/PartsFactory.h"
#include "../../Strategy/RacingStrategy.h"

class ResearchAndDevelopmentDepartment : public RacingStrategy
{
/**
     * @author Jason Maritz u19053292
     * @brief Parent class to define how a R&D department should function
     */
private:
    Part* part = nullptr;
    RacingStrategy* component = nullptr;
public:
/**
 *
 * @return return a vector of experimentalParts to be tested
 */
    std::vector<Part*> getExperimentalParts(){std::vector<Part*> t = experimentalParts; experimentalParts.clear();return t;};
    virtual void developParts() = 0;
    /**
     * virtual function to create parts
     * @param type : defines the type of part to create
     * @return Part* : a pointer to the created part
     */
    virtual Part* makePart(std::string type) = 0;
    /**
     * virtual function to create parts, and mutate their members with the provided params
     * @param type : defines the type of part to create
     * @param efficiency : a value to mutate the efficiency by
     * @param pcontrib : a value to mutate the powerContribution by
     * @param pdraw : a value to mutate the powerDraw by
     * @return Part* : a pointer to the created part
     */
    virtual Part* makePartExperimental(std::string type, double efficiency, double pcontrib, double pdraw) = 0;
    /**
     *
     * @return a string describing the part so that it can be recreated
     */
    string getStrategy() override;
    /**
     *
     * @param item : add the specified part to the component member
     */
    void add(RacingStrategy *item) override;
    /**
     *
     * @param newPart : new part to set the part member with
     */
    void setPart(Part* newPart);
protected:
    std::vector<Part*> experimentalParts;
    PartsFactory* myFactory;
    PartsFactory* myFactoryExperimental;
};


#endif //BENETTON_F1_RESEARCHANDDEVELOPMENTDEPARTMENT_H
