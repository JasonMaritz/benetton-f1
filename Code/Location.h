#include <string>
using namespace std;

#ifndef __Location_h__
#define __Location_h__

// #include "Destination.h"

class Destination;
class Location;

class Location
{
	private: string _name;
	private: bool _european;
	public: Destination* _unnamed_Destination_;
};

#endif
