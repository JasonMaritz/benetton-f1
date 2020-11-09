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
    if(t == "bargeboard"){
        aerodynamics->setBest(newBest);
    }else if (t == "drs"){
        aerodynamics->setBest(newBest);
    }else if (t == "ice"){
        engine->setBest(newBest);
    }else if (t == "turbocharger"){
        engine->setBest(newBest);
    }else if (t == "chassis"){
        chassis->setBest(newBest);
    }else if (t == "ers"){
        electronics->setBest(newBest);
    }else if (t == "mguh"){
        electronics->setBest(newBest);
    }else if (t == "mguk"){
        electronics->setBest(newBest);
    }else if (t == "energystore"){
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
