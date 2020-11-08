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
	ContainerSet* clone();
	double getWeight();
	PackedItem* getItem(string name);
	bool addItem(string name, PackedItem* item); //Returns false if name is already used
};

#endif