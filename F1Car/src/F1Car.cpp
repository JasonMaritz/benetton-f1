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

F1Car::~F1Car() {
    delete res;
    delete bargeboard;
    delete energyStore;
    delete drs;
    delete ice;
    delete turboCharger;
    delete chassisPart;
    delete ers;
    delete mguh;
    delete mguk;
}
