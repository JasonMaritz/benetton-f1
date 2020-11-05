// #include <exception>
// #include <string>
#include <vector>
using namespace std;

#ifndef __ContainerRoute_h__
#define __ContainerRoute_h__

// #include "ContainerSet.h"
// #include "Destination.h"
// #include "TransportMode.h"
#include "Location.h"
// #include "LowPriority.h"
// #include "HighPriority.h"
// #include "routeIterator.h"

class ContainerSet;
class Destination;
class TransportMode;
class Location;
class LowPriority;
class HighPriority;
class routeIterator;
class ContainerRoute;

class ContainerRoute
{
	private: ContainerSet* _containers;
	private: vector<Destination*> _stops;
	private: TransportMode* _transportMode;
	private: Location _currLocation;
	public: LowPriority* _unnamed_LowPriority_;
	public: HighPriority* _unnamed_HighPriority_;
	public: TransportMode* _unnamed_TransportMode_;
	public: ContainerSet* _unnamed_ContainerSet_;
	public: routeIterator* _unnamed_routeIterator_;
	public: TransportMode* _unnamed_TransportMode_2;

	public: routeIterator* getRouteIterator();

	public: void decideTransportMode();

	public: void setContainers(ContainerSet* aContainers);

	public: void setTransportMode(string aMode);

	public: Location getCurrLocation();

	public: void setCurrLocation(Location aCurrLocation);
};

#endif
