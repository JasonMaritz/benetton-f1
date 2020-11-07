#include "EuropeTestArea.h"

void EuropeTestArea::TestParts()
{
	double* arr = new double[PartList.size()];
	int icount = 0;
	for (vector<Part*>::iterator it = PartList.begin(); it != PartList.end(); it++)
	{
		arr[icount] = (*it)->getPerformance();
		icount++;
	}
	   
}
