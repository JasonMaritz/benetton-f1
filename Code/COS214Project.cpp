#include <iostream>

#include <ctime>

#include "LowPriority.h"

using namespace std;

void testSorting();

int main(){
	testSorting();
}

void testSorting() {
	//Sorting seems to work
	struct tm* t;
	t = new tm;
	t->tm_sec = 0;
	t->tm_min = 0;
	t->tm_hour = 0;
	t->tm_wday = 0;
	t->tm_yday = 0;
	t->tm_isdst = 0;

	t->tm_year = 120;
	t->tm_mon = 5;
	t->tm_mday = 14;

	time_t timeVal = mktime(t);
	LowPriority lp;
	Destination dests[10];
	dests[0].startDate = timeVal;

	t->tm_mday = 20;
	timeVal = mktime(t);
	dests[1].startDate = timeVal;

	t->tm_mon = 6;
	t->tm_mday = 3;
	timeVal = mktime(t);
	dests[2].startDate = timeVal;

	t->tm_mday = 8;
	timeVal = mktime(t);
	dests[3].startDate = timeVal;

	for (int i = 9; i > 3; i--) {
		t->tm_mday = 20 - i;
		timeVal = mktime(t);
		dests[i].startDate = timeVal;
	}
	lp.setDestinations(dests, 10);
	lp.setupRoutes();
	
}