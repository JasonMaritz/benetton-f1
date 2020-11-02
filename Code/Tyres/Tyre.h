//
// Created by chrissi-boi on 2020/11/02.
//

#ifndef RACINGSTRATEGY_TYRE_H
#define RACINGSTRATEGY_TYRE_H

#include <iostream>

using namespace std;

class Tyre
{
private:
    string type;
    double lapRatio;
    int wear;
    int temp;

public:
    virtual Tyre* make() = 0;
    virtual double getPerformance() = 0;

    string getType();
    int getWear();
    int getTemp();

protected:
    void setType(string type);
    void setWear(int wear);
    void setTemp(int temp);
};


#endif //RACINGSTRATEGY_TYRE_H
