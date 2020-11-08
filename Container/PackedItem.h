#ifndef PACKEDITEM_H
#define PACKEDITEM_H

class PackedItem{
public:
	double weight = 0;
	virtual PackedItem* clone(); 

};

#endif