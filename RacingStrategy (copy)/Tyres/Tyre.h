//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_TYRE_H
#define RACINGSTRATEGY_TYRE_H

#include <iostream>
#include "../Container/PackedItem.h"

using namespace std;

class Tyre : public PackedItem
{
private:
    string type;
    int wear;
    int temp;

public:
    /// @return Tyre* Object.
    virtual Tyre* make() = 0;
    /// @return A double value representing the tyre performance.
    virtual double getPerformance() = 0;

    /// @return A string giving detail to what type of tyre it is.
    string getType();
    /// @return An integer value for the current tyre wear.
    int getWear() const;
    /// @return An integer value for the current tyre temp.
    int getTemp() const;
    /// @param typeOfTyre The string value of what type of tyre to set the object to.
    void setType(string typeOfTyre);
    /// @param tyreWear An integer value to set the current tyre wear to.
    void setWear(int tyreWear);
    /// @param tyreTemp An integer value to set the current tyre temp to.
    void setTemp(int tyreTemp);
};


#endif //RACINGSTRATEGY_TYRE_H
