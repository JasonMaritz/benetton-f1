#ifndef CONTAINERSET_H
#define CONTAINERSET_H

#include <map>
#include <string>

#include "PackedItem.h"

using namespace std;

class ContainerSet{
private:
	map<string, PackedItem*> items;

public:
	ContainerSet();
	~ContainerSet();
	///@returns A deep copy of this
	ContainerSet* clone();
	///@returns summed weight of contained items
	double getWeight();
	///@param name the name, which is used as a key
	///@returns the corresponding item
	PackedItem* getItem(string name);
	///@param name name of item (key)
	///@param item actual item (value)
	///@returns true if name is unique, false if it's already taken
	bool addItem(string name, PackedItem* item);
};

#endif
