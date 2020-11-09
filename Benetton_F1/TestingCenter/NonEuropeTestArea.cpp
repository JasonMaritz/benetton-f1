#include "NonEuropeTestArea.h"

void NonEuropeTestArea::TestParts(bool WindTunnel, string TestName)
{
	Part** prt = new Part * [PartList.size()];
	if (WindTunnel)
	{
		double* arr = new double[PartList.size()];
		int icount = 0;
		for (vector<Part*>::iterator it = PartList.begin(); it != PartList.end(); it++)
		{
			try {
				arr[icount] = WTCounter->runWTTest((*it), 4);
				prt[icount] = (*it);
			}
			catch (string s)
			{
				cout << s << endl;
			}
			arr[icount] = (*it)->getPerformance();
			printTestReport((*it), arr[icount], TestName);
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

		cout << "Best part(" << prt[maxpos]->getType() << ") achieved a performance of: " << fixed << arr[maxpos] + icount/100.0;
	}
	else
	{
		double* arr = new double[PartList.size()];
		int icount = 0;
		for (vector<Part*>::iterator it = PartList.begin(); it != PartList.end(); it++)
		{
			arr[icount] = (*it)->getPerformance()+ (*it)->getPerformance()*0.1;
			prt[icount] = (*it);
			printTestReport((*it), arr[icount], TestName);
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

		cout << "Best part(" << prt[maxpos]->getType() << ") achieved a performance of: " << fixed << arr[maxpos];
	}
}

void NonEuropeTestArea::printTestReport(Part* prt, double perfomance, string TestName)
{
	ofstream tf(TestName+"_NonEuropeTestArea.txt");

	tf << prt->getType() << " achieved the following in the test: " << perfomance << endl;
	tf.close();
}
