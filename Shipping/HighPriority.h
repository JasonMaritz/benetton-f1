#include <exception>
#include <string>
#include <map>
#include <vector>
using namespace std;

#ifndef __HighPriority_h__
#define __HighPriority_h__

#include <iostream>
#include "../Container/ContainerRoute.h"
#include "TransportMode.h"
#include "Ship.h"
#include "Truck.h"
#include "ChartedPlane.h"

class ContainerRoute;
class Shipper;
class Destination;
class ContainerSet;
class HighPriority;

class HighPriority
{
	private: map<string, ContainerRoute*> _routes;

	private: int raceNum = 0 ;

	public: Shipper* _unnamed_Shipper_;
	// public: std::vector<ContainerRoute*> _unnamed_ContainerRoute_;

	public: void shipSomething(Destination* aDest, ContainerSet* aContainers, string aName);

	public: ContainerSet* get(string aName);

	public: void remove(string aName);

	public: virtual ~HighPriority() ; 
};

#endif
