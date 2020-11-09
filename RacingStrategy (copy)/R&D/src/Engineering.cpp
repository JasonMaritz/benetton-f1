//
// Created by jason on 2020/11/03.
//

#include "../include/Engineering.h"
#include "../../PartsFactory/include/AFactory.h"

Engineering* Engineering::instance = nullptr;
Engineering *Engineering::getInstance()
{
    if(!instance)
    {
        instance = new Engineering();
    }
    return instance;
}

void Engineering::setBest(Part *newBest) {
    std::string t = newBest->getType();
    if(t == "Bargeboard"){
        aerodynamics->setBest(newBest);
    }else if (t == "DRS"){
        aerodynamics->setBest(newBest);
    }else if (t == "ICE"){
        engine->setBest(newBest);
    }else if (t == "TurboCharger"){
        engine->setBest(newBest);
    }else if (t == "Chassis"){
        chassis->setBest(newBest);
    }else if (t == "ERS"){
        electronics->setBest(newBest);
    }else if (t == "MGUH"){
        electronics->setBest(newBest);
    }else if (t == "MGUK"){
        electronics->setBest(newBest);
    }else if (t == "EnergyStore"){
        electronics->setBest(newBest);
    }

}

Engineering::Engineering() {
    engine = new Engine();
    electronics = new Electronics();
    chassis = new Chassis();
    aerodynamics = new Aerodynamics();
}

void Engineering::develop() {
    while(budget != 2000){
        budget -= 2000;
        int r = rand()%4;
        switch (r){
            case 1:
                engine->developParts();
                break;
            case 2:
                aerodynamics->developParts();
                break;
            case 3:
                electronics->developParts();
                break;
            case 4:
                chassis->developParts();
                break;
        }
    }
}
