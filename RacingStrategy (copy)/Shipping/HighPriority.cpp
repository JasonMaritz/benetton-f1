#include "HighPriority.h"


using namespace std;

bool HighPriority::shipSomething(Destination* aDest, ContainerSet* aContainers, string aName)
{
	if (_routes.find(aName) != _routes.end())
    {
        return false;
    }

	auto * newRoute = new ContainerRoute(aContainers) ;
	vector<Destination*> v ; 
	v.push_back(aDest) ;
	newRoute->setStops(&v) ;
	// if name already exist ?
	_routes.insert(std::pair<string,ContainerRoute*>(aName,newRoute)) ;

	TransportMode* assignedMode ;
	if (aDest->location.european){
		assignedMode = new Truck(aDest->location,newRoute) ;
	}
	else
    {
		assignedMode = new ChartedPlane(aDest->location,newRoute) ;
	}

	newRoute->setTransportMode(assignedMode) ;

	_routes[aName] = newRoute;
    return true;
}

HighPriority::~HighPriority()
{
	//iterate through map to delete
	_routes.clear();
}

ContainerSet* HighPriority::get(string aName)
{
	ContainerRoute* r = _routes.at(aName) ;
	if (r == nullptr)
    {
	    return nullptr ;
    }

	TransportMode* t = r->getTransportMode() ; 
	if (t != nullptr)
	{
		if (!t->getOnRoute())
		{
			return r->getContainers() ; 
		}
	} 

	return nullptr ;
}

void HighPriority::remove(string aName)
{
	
	ContainerRoute* r = _routes.at(aName) ;
	if (r  == nullptr) {
		cout<<"404 Item not found. \n" ; 
	} 
	_routes.erase(aName) ;
}

