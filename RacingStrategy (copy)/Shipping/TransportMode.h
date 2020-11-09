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
		
	/// @param aDest specifies the destination for the shipment
	/// @param r pointer to a ContainerRoute 
	/// @param a speed of the tranportMode
	 	TransportMode(Location aDest, ContainerRoute* r,int aSpeed);

	public: 
		/// @param aDestination the destination for shipment
		virtual time_t eta(Location& aDestination) = 0;
		
		/// @todo changes method for offloading
		virtual void changeTransportMode(bool =false ) = 0;
		
		/// @returns whether transport is on route or not
		bool getOnRoute();

		/// @param aOnRoute specifies whether transport is on route or not
	 	void setOnRoute(bool aOnRoute);

		/// @returns the route that is currently on
		ContainerRoute* getRoute();
		
		/// @param aRoute ContainerRoute that the mode should be on
		void setRoute(ContainerRoute* aRoute);
		
		/// @returns the current destination that is fulfiling/fulled. 
		Location getDestination();
		
		/// @param aDestination sets the destination, shipment should be dilivered to. 
		void setDestination(Location aDestination);

		~TransportMode() ;
};

#endif
