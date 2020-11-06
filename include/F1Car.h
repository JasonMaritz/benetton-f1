//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1CAR_H
#define BENETTON_F1_F1CAR_H

#include <vector>
#include "Part.h"

class F1Car {
    friend class F1Builder;
public:
    F1Car();
    ~F1Car();
    double getPerformance();
    void setResult(Result* result);
    void generateReport();
private:
    Result* res;
    std::vector<Part*> parts;
};

#endif //BENETTON_F1_F1CAR_H
