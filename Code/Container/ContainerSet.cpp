#include "ContainerSet.h"

ContainerSet::ContainerSet() {}

ContainerSet::~ContainerSet()
{
	for (auto it = items.begin(); it != items.end(); it++) {
		delete it->second;
	}
}

ContainerSet* ContainerSet::clone()
{
	ContainerSet* newContainer = new ContainerSet();
	
	for(auto it = items.begin(); it != items.end(); it++){
		newContainer->addItem(it->first, it->second->clone());
	}
	return newContainer;
}

double ContainerSet::getWeight() {
	double total = 0;
	for (auto it = items.begin(); it != items.end(); it++) {
		total += (it->second)->weight;
	}
	return total;
}

PackedItem* ContainerSet::getItem(string name) {
	auto it = items.find(name);
	if (it == items.end())
		return 0;
	return it->second;
}

bool ContainerSet::addItem(string name, PackedItem* addThis) {
	if (getItem(name))
		return false; //Name is already used, keys must be unique
	items[name] = addThis;
	return true;
}