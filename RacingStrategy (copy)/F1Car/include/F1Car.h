//
// Created by jason on 2020/11/03.
//

#ifndef BENETTON_F1_F1CAR_H
#define BENETTON_F1_F1CAR_H

#include "../../Parts/include/Bargeboard.h"
#include "../../Parts/include/DRS.h"
#include "../../Parts/include/ICE.h"
#include "../../Parts/include/TurboCharger.h"
#include "../../Parts/include/ChassisPart.h"
#include "../../Parts/include/ERS.h"
#include "../../Parts/include/MGUH.h"
#include "../../Parts/include/MGUK.h"
#include "../../Parts/include/EnergyStore.h"

class Result;

class F1Car
{
    friend class F1Builder;
public:
    ~F1Car(){if(res) delete res;};
    double getPerformance();
    void setResult(Result* result){res = result;};
    void generateReport();
    void setDriverName(string name);
    void setCarName(string name);
    string getDriverName();
    string getCarName();
    void setQualifyingTime(double time);
    void setLapTime(double time);
    void setRaceTime(double time);
    double getQualifyingTime();
    double getLapTime();
    double getRaceTime();
private:
    Result* res = nullptr;
    Bargeboard* bargeboard= nullptr;
    DRS* drs= nullptr;
    ICE* ice= nullptr;
    TurboCharger* turboCharger= nullptr;
    ChassisPart* chassisPart= nullptr;
    ERS* ers= nullptr;
    MGUH* mguh= nullptr;
    MGUK* mguk= nullptr;
    EnergyStore* energyStore= nullptr;
    string driverName;
    string carName;
    double qualifyingTime;
    double lapTime = 0;
    double raceTime = 0;

    std::vector<Part *> generateParts();
};

#endif //BENETTON_F1_F1CAR_H
