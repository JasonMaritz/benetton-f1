//
// Created by jason on 2020/11/03.
//

#include "../include/F1Car.h"

double F1Car::getPerformance() {
    double res = 0;
    res += bargeboard->getPerformance();
    res += drs->getPerformance();
    res += ice->getPerformance();
    res += turboCharger->getPerformance();
    res += chassisPart->getPerformance();
    res += ers->getPerformance();
    res += mguh->getPerformance();
    res += mguk->getPerformance();
    res += energyStore->getPerformance();
    res /= 9;
    return res;
}