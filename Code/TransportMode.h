#include <exception>
#include <string>
using namespace std;

#ifndef __TransportMode_h__
#define __TransportMode_h__

// #include "ContainerRoute.h"
#include "Location.h"

class ContainerRoute;
class Location;
class TransportMode;

class TransportMode
{
	private: int _speed;
	private: bool _onRoute;
	protected: ContainerRoute* _route;
	private: Location _destination;

	public: virtual time_t eta(Location aDestination) = 0;

	protected: TransportMode(int aSpeed, Location aCurr);

	public: virtual void changeTransportMode() = 0;

	public: bool getOnRoute();

	public: void setOnRoute(bool aOnRoute);

	public: ContainerRoute* getRoute();

	public: void setRoute(ContainerRoute* aRoute);

	public: Location getDestination();

	public: void setDestination(Location aDestination);
};

#endif
