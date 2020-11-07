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
    virtual Tyre* make() = 0;
    virtual double getPerformance() = 0;

    string getType();
    int getWear() const;
    int getTemp() const;

protected:
    void setType(string typeOfTyre);
    void setWear(int tyreWear);
    void setTemp(int tyreTemp);
};


#endif //RACINGSTRATEGY_TYRE_H
