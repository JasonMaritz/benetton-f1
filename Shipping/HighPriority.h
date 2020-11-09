#ifndef __HighPriority_h__
#define __HighPriority_h__

#include <exception>
#include <string>
#include <map>
#include <vector>

#include <iostream>
#include "../Container/ContainerRoute.h"
#include "../Container/ContainerSet.h"

#include "TransportMode.h"
#include "Ship.h"
#include "Truck.h"
#include "ChartedPlane.h"

using namespace std;

class HighPriority
{
	private: map<string, ContainerRoute*> _routes;

	private: int raceNum = 0 ;

	public: bool shipSomething(Destination* aDest, ContainerSet* aContainers, string aName);

	public: ContainerSet* get(string aName);

	public: void remove(string aName);

	public: virtual ~HighPriority() ; 
};

#endif
