#include <exception>
#include <string>
using namespace std;

#ifndef __TransportMode_h__
#define __TransportMode_h__

#include "../Container/ContainerRoute.h"
#include "../Container/Location.h"


class ContainerRoute;
// class Location;
// class TransportMode;

class TransportMode
{	
	private:
		bool onRoute;
		Location _destination;
	
	protected:
		int speed;
		ContainerRoute* _route;
	 	TransportMode(Location aDest, ContainerRoute* r,int aSpeed);

	public: 
		virtual time_t eta(Location aDestination) = 0;
		
		virtual void changeTransportMode(bool ) = 0;
		
		bool getOnRoute();

	 	void setOnRoute(bool aOnRoute);

		ContainerRoute* getRoute();
		
		void setRoute(ContainerRoute* aRoute);
		
		Location getDestination();
		
		void setDestination(Location aDestination);

		~TransportMode() ;
};

#endif
