#include "EuropeTestArea.h"
#include <fstream>

void EuropeTestArea::TestParts(bool WindTunnel, string TestName)
{
	if (WindTunnel)
	{
		double* arr = new double[PartList.size()];
		int icount = 0;
		for (vector<Part*>::iterator it = PartList.begin(); it != PartList.end(); it++)
		{
			try {
				arr[icount] = WTCounter->runWTTest((*it), 2);
			}
			catch (string s)
			{
				cout << s << endl;
			}
			arr[icount] = (*it)->getPerformance();
			icount++;
		}

		int maxpos = 0;
		for (int i = 0; i < icount; i++)
		{
			if (arr[i] > arr[maxpos])
			{
				maxpos = i;
			}
		}
	}
	else
	{
		double* arr = new double[PartList.size()];
		int icount = 0;
		for (vector<Part*>::iterator it = PartList.begin(); it != PartList.end(); it++)
		{
			arr[icount] = (*it)->getPerformance() + (*it)->getPerformance() * 0.1;
			icount++;
		}

		int maxpos = 0;
		for (int i = 0; i < icount; i++)
		{
			if (arr[i] > arr[maxpos])
			{
				maxpos = i;
			}
		}
	}
	
}

void EuropeTestArea::printTestReport(Part* prt, double performance, string TestName)
{
	ofstream tf(TestName + "_EuropeTestArea.txt");

	tf << prt->getType() << " achieved the following in the test: " << performance;
	tf.close();
}
