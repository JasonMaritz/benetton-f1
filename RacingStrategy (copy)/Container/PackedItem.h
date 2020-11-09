#ifndef PACKEDITEM_H
#define PACKEDITEM_H

class PackedItem{
public:
	double weight = 0;
	///@returns a deep copy of this
	virtual PackedItem* clone(); 

};

#endif