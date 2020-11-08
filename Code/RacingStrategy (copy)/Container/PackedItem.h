#ifndef PACKEDITEM_H
#define PACKEDITEM_H

class PackedItem
{
private:
public:
	double weight = 0;
	virtual PackedItem* clone();
};

#endif